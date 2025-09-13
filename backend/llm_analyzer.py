#!/usr/bin/env python3
"""
LLM Analyzer Module
Handles chunking and analysis of disassembled code using Anthropic's API
"""

import json
import os
import shutil
import sys
import getpass
import time
from pathlib import Path
from typing import List, Dict, Optional
from dataclasses import dataclass
try:
    import anthropic  # type: ignore
    from anthropic import Anthropic  # type: ignore
    _HAVE_ANTHROPIC = True
except Exception:
    anthropic = None  # type: ignore
    Anthropic = None  # type: ignore
    _HAVE_ANTHROPIC = False

@dataclass
class AnalysisChunk:
    """Represents a chunk of content for analysis"""
    content: str
    chunk_type: str  # 'code' or 'data'
    chunk_index: int
    start_line: int = 0
    end_line: int = 0

@dataclass
class AnalysisResult:
    """Container for analysis results"""
    chunk_type: str
    chunk_index: int
    analysis: str
    tokens_used: int = 0

class LLMAnalyzer:
    def __init__(self, api_key: str = None, model: str = "claude-sonnet-4-20250514", disable_chunking: bool = True):
        """
        Initialize the LLM Analyzer
        
        Args:
            api_key: Anthropic API key (optional, can use env var)
            model: Model to use for analysis
        """
        if _HAVE_ANTHROPIC:
            self.api_key = self._get_api_key(api_key)
            self.client = Anthropic(api_key=self.api_key)
        else:
            self.api_key = None
            self.client = None
            # Surface a concise hint so users don't silently hit offline fallback
            print("[LLMAnalyzer] Anthropic SDK not found in this interpreter; running offline fallback.")
        self.model = model
        self.max_chunk_size = 8000  # Max tokens per chunk
        self.storage_dir = self._get_storage_dir()
        self.disable_chunking = disable_chunking

    def _sanitize_basename(self, name: str) -> str:
        """Create a safe base filename without extensions or spaces."""
        base = Path(name).stem
        return "".join(c for c in base if c.isalnum() or c in ("-", "_")) or "output"
    
    def _get_storage_dir(self) -> Path:
        """Get the storage directory"""
        current_dir = Path(__file__).parent
        
        if current_dir.name == 'backend':
            storage_dir = current_dir.parent / 'storage'
        else:
            storage_dir = Path('../storage').resolve()
            if not storage_dir.exists():
                storage_dir = current_dir.parent / 'storage'
        
        return storage_dir

    def _get_results_dir(self) -> Path:
        """Get the results directory under storage (repo-root/storage/results)."""
        # Always place results inside the existing storage directory
        results_dir = self.storage_dir / 'results'
        results_dir.mkdir(parents=True, exist_ok=True)
        return results_dir
    
    def _get_api_key(self, provided_key: str = None) -> str:
        """
        Get API key from various sources
        
        Args:
            provided_key: Directly provided API key
            
        Returns:
            Valid API key
        """
        # Priority order: provided key, env var, project config, user config
        if provided_key:
            return provided_key
        
        # Check environment variable
        if os.environ.get('ANTHROPIC_API_KEY'):
            return os.environ.get('ANTHROPIC_API_KEY')

        # Check project-local config files (useful for per-repo setup)
        try:
            here = Path(__file__).parent
        except Exception:
            here = Path.cwd()

        local_candidates = [
            here / 'config.json',               # backend/config.json
            here.parent / 'config.json',        # repo-root/config.json
            Path.cwd() / 'backend' / 'config.json',
            Path.cwd() / 'config.json',
        ]
        for cfg in local_candidates:
            try:
                if cfg.exists():
                    with open(cfg, 'r') as f:
                        config = json.load(f)
                        key = config.get('anthropic_api_key')
                        if key:
                            return key
            except Exception:
                # Ignore malformed local config; fall through to other sources
                pass

        # Check user config in home directory
        config_file = Path.home() / '.config' / 'ghidra-llm' / 'config.json'
        if config_file.exists():
            with open(config_file, 'r') as f:
                config = json.load(f)
                if config.get('anthropic_api_key'):
                    return config.get('anthropic_api_key')
        
        # If no key found, prompt for it
        print("No API key found. Please provide one:")
        return self._prompt_for_api_key()
    
    def _prompt_for_api_key(self) -> str:
        """Interactively prompt for API key"""
        api_key = getpass.getpass("Enter your Anthropic API key: ")
        
        # Offer to save for future use
        save_response = input("Save this key for future use? (y/n): ").lower()
        if save_response == 'y':
            config_dir = Path.home() / '.config' / 'ghidra-llm'
            config_dir.mkdir(parents=True, exist_ok=True)
            config_file = config_dir / 'config.json'
            
            config = {'anthropic_api_key': api_key}
            with open(config_file, 'w') as f:
                json.dump(config, f, indent=2)
            
            # Set restrictive permissions on Unix-like systems
            if os.name != 'nt':
                os.chmod(config_file, 0o600)
            
            print(f"API key saved to {config_file}")
        
        return api_key
    
    def chunk_content(self, content: str, chunk_type: str) -> List[AnalysisChunk]:
        """
        Split content into chunks suitable for LLM processing
        
        Args:
            content: Content to chunk
            chunk_type: Type of content ('code' or 'data')
            
        Returns:
            List of AnalysisChunk objects
        """
        chunks = []
        lines = content.split('\n')
        current_chunk = []
        current_size = 0
        chunk_index = 0
        start_line = 0
        
        # Estimate 4 characters per token
        chars_per_token = 4
        max_chars = self.max_chunk_size * chars_per_token
        
        for i, line in enumerate(lines):
            line_size = len(line)
            
            # Check if adding this line would exceed chunk size
            if current_size + line_size > max_chars and current_chunk:
                # Save current chunk
                chunk_content = '\n'.join(current_chunk)
                chunks.append(AnalysisChunk(
                    content=chunk_content,
                    chunk_type=chunk_type,
                    chunk_index=chunk_index,
                    start_line=start_line,
                    end_line=i - 1
                ))
                chunk_index += 1
                start_line = i
                current_chunk = [line]
                current_size = line_size
            else:
                current_chunk.append(line)
                current_size += line_size
        
        # Add remaining content
        if current_chunk:
            chunk_content = '\n'.join(current_chunk)
            chunks.append(AnalysisChunk(
                content=chunk_content,
                chunk_type=chunk_type,
                chunk_index=chunk_index,
                start_line=start_line,
                end_line=len(lines) - 1
            ))
        
        return chunks
    
    def analyze_chunk(self, chunk: AnalysisChunk, 
                     custom_prompt: str = None) -> AnalysisResult:
        """
        Send a chunk to Anthropic API for analysis
        
        Args:
            chunk: AnalysisChunk to analyze
            custom_prompt: Custom analysis prompt
            
        Returns:
            AnalysisResult object
        """
        if not custom_prompt:
            if chunk.chunk_type == 'code':
                custom_prompt = """Analyze this decompiled C code from Ghidra. 
                Identify:
                1. Main functionality and purpose
                2. Potential vulnerabilities or security issues
                3. Interesting algorithms or logic patterns
                4. Key functions and their relationships
                5. Suggestions for improvement or understanding"""
            else:
                custom_prompt = """Analyze this data section from a disassembled binary.
                Identify:
                1. Data structures and their purposes
                2. Strings and their potential uses
                3. Memory layout patterns
                4. Interesting constants or addresses
                5. Relationships between data elements"""
        
        prompt = f"""{custom_prompt}

Chunk Type: {chunk.chunk_type}
Chunk Index: {chunk.chunk_index}
Lines: {chunk.start_line}-{chunk.end_line}

Content:
```
{chunk.content}
```
"""
        
        if self.client is None:
            return AnalysisResult(
                chunk_type=chunk.chunk_type,
                chunk_index=chunk.chunk_index,
                analysis="Anthropic client unavailable; skipped LLM analysis.",
                tokens_used=0
            )
        try:
            response = self.client.messages.create(
                model=self.model,
                max_tokens=4000,
                temperature=0,
                messages=[
                    {"role": "user", "content": prompt}
                ]
            )
            
            # Extract token usage if available
            tokens_used = getattr(response.usage, 'total_tokens', 0) if hasattr(response, 'usage') else 0
            
            return AnalysisResult(
                chunk_type=chunk.chunk_type,
                chunk_index=chunk.chunk_index,
                analysis=response.content[0].text,
                tokens_used=tokens_used
            )
        except Exception as e:
            print(f"Error calling Anthropic API: {e}")
            return AnalysisResult(
                chunk_type=chunk.chunk_type,
                chunk_index=chunk.chunk_index,
                analysis=f"Error analyzing chunk: {str(e)}",
                tokens_used=0
            )
    
    def analyze_file(self, file_path: str, file_type: str = 'code',
                    custom_prompt: str = None,
                    disable_chunking: Optional[bool] = None) -> List[AnalysisResult]:
        """
        Analyze a complete file by chunking and processing
        
        Args:
            file_path: Path to file to analyze
            file_type: Type of file ('code' or 'data')
            custom_prompt: Custom analysis prompt
            
        Returns:
            List of AnalysisResult objects
        """
        print(f"Analyzing {file_type} file: {file_path}")
        
        # Read file content
        with open(file_path, 'r') as f:
            content = f.read()
        
        # Create chunks (optionally disabled to send as a single chunk)
        no_chunk = self.disable_chunking if disable_chunking is None else disable_chunking
        if no_chunk:
            chunks = [AnalysisChunk(
                content=content,
                chunk_type=file_type,
                chunk_index=0,
                start_line=0,
                end_line=len(content.split('\n')) - 1
            )]
        else:
            chunks = self.chunk_content(content, file_type)
        print(f"Created {len(chunks)} chunks for analysis")
        
        # Analyze each chunk
        results = []
        for chunk in chunks:
            print(f"Analyzing {file_type} chunk {chunk.chunk_index + 1}/{len(chunks)}...")
            result = self.analyze_chunk(chunk, custom_prompt)
            results.append(result)
        
        return results

    def annotate_types_and_summarize(self,
                                     c_file_path: str,
                                     objdump_path: Optional[str] = None,
                                     out_ext: str = 'c') -> Dict[str, str]:
        """
        Use the LLM to infer and insert explicit types for functions/variables
        in a decompiled C file, and produce a concise textual summary.

        Args:
            c_file_path: Path to the decompiled C file to annotate
            objdump_path: Optional path to an objdump/data text to aid typing
            out_ext: Extension for the typed code output (e.g., 'c' or 'txt')

        Returns:
            Dict with keys: 'typed_code_file', 'summary_file'
        """
        with open(c_file_path, 'r') as f:
            c_content = f.read()

        objdump_content = None
        if objdump_path and Path(objdump_path).exists():
            # Read a bounded amount to avoid excessive tokens
            with open(objdump_path, 'r', errors='ignore') as f:
                objdump_content = f.read(200_000)

        base_name = self._sanitize_basename(Path(c_file_path).name)
        results_dir = self._get_results_dir()
        out_code = results_dir / f"{base_name}_typed.{out_ext or 'c'}"
        out_summary = results_dir / f"{base_name}_summary.txt"
        combined_input = results_dir / f"{base_name}_combined.txt"

        # Persist a combined view of inputs for traceability and optional reuse
        try:
            with open(combined_input, 'w') as f:
                f.write("=== SOURCE_C_START ===\n")
                f.write(c_content.rstrip() + "\n")
                f.write("=== SOURCE_C_END ===\n")
                if objdump_content:
                    f.write("\n=== OBJ_DUMP_START ===\n")
                    f.write(objdump_content.rstrip() + "\n")
                    f.write("=== OBJ_DUMP_END ===\n")
        except Exception:
            # Do not fail the analysis if writing the combined file has issues
            pass

        system_instructions = (
            "You are a reverse engineering assistant. Given decompiled C code "
            "from Ghidra and optionally objdump output, infer strong typing for "
            "function signatures and local variables. Replace ambiguous types "
            "(e.g., int/undefined/void* when inappropriate) with the most likely "
            "concrete types based on calling conventions, pointer arithmetic, "
            "string usage, and arithmetic width. Maintain identical logic, names, "
            "and structure, only improving types and adding const/restrict where obvious. "
            "Do not add comments except where necessary to indicate assumptions."
        )

        prompt = (
            "Task: Produce two artifacts.\n"
            "1) TYPED_CODE: Full C code with improved/explicit types and better variable names so the code is more human readable.\n"
            "2) SUMMARY: Short explanation of how the code works.\n\n"
            "Constraints:\n"
            "- Preserve original logic and control flow.\n"
            "- Keep function and variable names unless obviously autogenerated.\n"
            "- Ensure compilable C.\n"
            "- Clearly separate outputs using the exact markers below.\n\n"
            "Markers:\n"
            "===TYPED_CODE_START===\n"
            "... C code here ...\n"
            "===TYPED_CODE_END===\n"
            "===SUMMARY_START===\n"
            "... plain text summary here ...\n"
            "===SUMMARY_END===\n\n"
            f"C File ({Path(c_file_path).name}):\n```c\n{c_content[:200000]}\n```\n"
        )

        if objdump_content:
            prompt += f"\nObjdump/Data ({Path(objdump_path).name} excerpt):\n```\n{objdump_content}\n```\n"

        text = None
        last_error: Optional[Exception] = None
        
        def _fmt_error(err: Exception) -> str:
            parts = [f"{err.__class__.__name__}: {err}"]
            # Try to include extra context from common HTTP/API exceptions
            for attr in ("status_code", "code", "message"):
                if hasattr(err, attr):
                    parts.append(f"{attr}={getattr(err, attr)}")
            resp = getattr(err, "response", None)
            if resp is not None:
                try:
                    # Some SDKs expose .text or .json() on response
                    body = getattr(resp, "text", None) or getattr(resp, "content", None)
                    parts.append(f"response_body={str(body)[:500]}")
                except Exception:
                    pass
            return " | ".join(parts)

        if self.client is not None:
            max_retries = 3
            for attempt in range(1, max_retries + 1):
                try:
                    response = self.client.messages.create(
                        model=self.model,
                        max_tokens=4000,
                        temperature=0,
                        system=system_instructions,
                        messages=[
                            {"role": "user", "content": prompt}
                        ]
                    )
                    text = response.content[0].text
                    if attempt > 1:
                        print(f"[LLMAnalyzer] Succeeded on retry {attempt} of {max_retries}.")
                    break
                except Exception as e:
                    last_error = e
                    msg = _fmt_error(e)
                    print(f"[LLMAnalyzer] Typing/summarization attempt {attempt}/{max_retries} failed: {msg}")
                    if attempt < max_retries:
                        delay = min(2 ** attempt, 8)
                        print(f"[LLMAnalyzer] Retrying in {delay}s...")
                        try:
                            time.sleep(delay)
                        except KeyboardInterrupt:
                            raise
                    else:
                        print("[LLMAnalyzer] All attempts failed; using offline fallback.")
        if text is None:
            # Offline fallback: keep original code and a minimal heuristic summary
            func_headers = []
            for line in c_content.splitlines():
                s = line.strip()
                if s and '(' in s and ')' in s and s.endswith('{') and not s.startswith('//'):
                    func_headers.append(s)
                if len(func_headers) >= 20:
                    break
            summary_lines = [
                "Offline fallback: unable to contact LLM.",
                f"File: {Path(c_file_path).name}",
                f"Approx. function headers detected: {len(func_headers)}",
            ]
            if last_error is not None:
                summary_lines.append(f"LLM error: {_fmt_error(last_error)}")
            if func_headers:
                summary_lines.append("Sample headers:")
                summary_lines.extend(f"- {h}" for h in func_headers[:5])
            text = (
                "===TYPED_CODE_START===\n" + c_content + "\n===TYPED_CODE_END===\n"
                "===SUMMARY_START===\n" + "\n".join(summary_lines) + "\n===SUMMARY_END===\n"
            )

        # Extract typed code and summary between markers
        def _between(s: str, a: str, b: str) -> Optional[str]:
            i = s.find(a)
            if i == -1:
                return None
            i += len(a)
            j = s.find(b, i)
            if j == -1:
                return None
            return s[i:j].strip()

        typed_code = _between(text, "===TYPED_CODE_START===", "===TYPED_CODE_END===")
        summary = _between(text, "===SUMMARY_START===", "===SUMMARY_END===")

        # Fallbacks
        if not typed_code:
            typed_code = c_content
        if not summary:
            summary = "No summary generated."

        # Save files
        with open(out_code, 'w') as f:
            f.write(typed_code.rstrip() + "\n")
        with open(out_summary, 'w') as f:
            f.write(summary.rstrip() + "\n")

        print(f"Saved typed code to: {out_code}")
        print(f"Saved summary to: {out_summary}")
        print(f"Saved combined input to: {combined_input}")

    # ========== CLEANUP GHIDRA PROJECT FOLDER ==========
        # try:#UNCOMMENT
        #     print("Cleaning up Ghidra project folder...")
            
        #     # Wait a moment to ensure all file handles are released
        #     import time
        #     time.sleep(1)
        #     project_dir = Path("./decompiled_output").resolve()
        #     if project_dir.exists():
        #         # Delete the entire ghidra_projects folder
        #         shutil.rmtree(project_dir)
        #         print(f"Deleted: {project_dir}")
        #     else:
        #         print(f"Project folder already gone: {project_dir}")
                
        # except Exception as e:
        #     print(f"Could not delete project folder: {e}")
        #     print(f"You can manually delete: {project_dir}")

        return {
            'typed_code_file': str(out_code),
            'summary_file': str(out_summary),
            'combined_input_file': str(combined_input),
        }
    
    def save_analysis(self, results: List[AnalysisResult], base_name: str) -> str:
        """
        Save analysis results to JSON file
        
        Args:
            results: List of AnalysisResult objects
            base_name: Base name for output file
            
        Returns:
            Path to saved file
        """
        # Convert results to dictionaries
        results_data = []
        for result in results:
            results_data.append({
                'chunk_type': result.chunk_type,
                'chunk_index': result.chunk_index,
                'analysis': result.analysis,
                'tokens_used': result.tokens_used
            })
        
        # Save to file
        output_file = self.storage_dir / f"{base_name}_analysis.json"
        with open(output_file, 'w') as f:
            json.dump(results_data, f, indent=2)
        
        print(f"Saved analysis to: {output_file}")
        return str(output_file)
    
    def generate_summary(self, results: List[AnalysisResult]) -> str:
        """
        Generate a summary of all analysis results
        
        Args:
            results: List of AnalysisResult objects
            
        Returns:
            Summary text
        """
        # Combine all analyses for summary
        all_analyses = "\n\n".join([
            f"[{r.chunk_type.upper()} Chunk {r.chunk_index}]\n{r.analysis}"
            for r in results
        ])
        
        prompt = f"""Based on the following chunk analyses of a disassembled binary, 
        provide a comprehensive summary including:
        1. Overall purpose and functionality of the program
        2. Key security findings and vulnerabilities
        3. Important data structures and algorithms
        4. Recommendations for further analysis
        
        Chunk Analyses:
        {all_analyses[:15000]}  # Limit to avoid token limits
        """
        
        if self.client is None:
            return "LLM unavailable; no combined summary generated."
        try:
            response = self.client.messages.create(
                model=self.model,
                max_tokens=2000,
                temperature=0,
                messages=[
                    {"role": "user", "content": prompt}
                ]
            )
            return response.content[0].text
        except Exception as e:
            return f"Error generating summary: {str(e)}"
    def _cleanup_decompiled_output(self):
        """
        Clean up the decompiled_output folder after processing is complete
        """
        try:
            print("[LLMAnalyzer] Cleaning up decompiled_output folder...")
            
            # Look for decompiled_output folder in common locations
            possible_locations = [
                Path("./decompiled_output"),                    # Current directory
                Path("../decompiled_output"),                   # Parent directory
                Path(__file__).parent / "decompiled_output",    # Same as script
                Path(__file__).parent.parent / "decompiled_output"  # Parent of script
            ]
            
            deleted = False
            for decompiled_dir in possible_locations:
                if decompiled_dir.exists() and decompiled_dir.is_dir():
                    print(f"[LLMAnalyzer] Found decompiled_output at: {decompiled_dir.resolve()}")
                    
                    # Wait a moment to ensure all file handles are released
                    time.sleep(1)
                    
                    # Delete the folder
                    shutil.rmtree(decompiled_dir)
                    print(f"[LLMAnalyzer] Deleted: {decompiled_dir.resolve()}")
                    deleted = True
                    break
            
            if not deleted:
                print("[LLMAnalyzer] No decompiled_output folder found to clean up")
                
        except Exception as e:
            print(f"[LLMAnalyzer] Could not delete decompiled_output folder: {e}")
            print("[LLMAnalyzer] You can manually delete it if needed")
def main():
    """Standalone usage of LLM analyzer"""
    import argparse
    
    parser = argparse.ArgumentParser(description='LLM Code Analyzer')
    parser.add_argument('file', help='Path to file to analyze')
    parser.add_argument('--type', choices=['code', 'data'], default='code',
                       help='Type of file to analyze')
    parser.add_argument('--api-key', help='Anthropic API key')
    parser.add_argument('--prompt', help='Custom analysis prompt')
    parser.add_argument('--model', default='claude-sonnet-4-20250514',
                       help='Model to use for analysis')
    parser.add_argument('--chunk', action='store_true',
                       help='Enable chunking (disabled by default)')
    
    args = parser.parse_args()
    
    analyzer = LLMAnalyzer(api_key=args.api_key, model=args.model, disable_chunking=(not args.chunk))
    
    # Analyze file
    results = analyzer.analyze_file(
        file_path=args.file,
        file_type=args.type,
        custom_prompt=args.prompt,
        disable_chunking=(not args.chunk)
    )
    
    # Save results
    base_name = Path(args.file).stem.replace('_code', '').replace('_data', '')
    output_file = analyzer.save_analysis(results, base_name)
    
    # Calculate total tokens
    total_tokens = sum(r.tokens_used for r in results)
    
    print("\n=== Analysis Complete ===")
    print(f"Analyzed {len(results)} chunks")
    print(f"Total tokens used: {total_tokens}")
    print(f"Results saved to: {output_file}")
    analyzer._cleanup_decompiled_output()

if __name__ == "__main__":
    main()
