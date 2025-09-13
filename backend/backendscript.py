#!/usr/bin/env python3
"""
Ghidra CLI LLM Assistant
Disassembles binaries using ghidra-cli, separates output into data and code sections,
and sends chunks to Anthropic API for analysis.
"""

import subprocess
import json
import os
import re
import sys
from pathlib import Path
from typing import List, Dict, Tuple, Optional
import argparse
from dataclasses import dataclass
import anthropic
from anthropic import Anthropic

@dataclass
class DisassemblyChunk:
    """Represents a chunk of disassembled code or data"""
    content: str
    chunk_type: str  # 'code' or 'data'
    start_address: Optional[str] = None
    end_address: Optional[str] = None
    chunk_index: int = 0

class GhidraLLMAssistant:
    def __init__(self, api_key: str, ghidra_path: str = "ghidra-cli"):
        """
        Initialize the Ghidra LLM Assistant
        
        Args:
            api_key: Anthropic API key
            ghidra_path: Path to ghidra-cli executable
        """
        self.ghidra_path = ghidra_path
        self.client = Anthropic(api_key=api_key)
        self.max_chunk_size = 8000  # Max tokens per chunk (conservative estimate)
        
    def run_ghidra_cli(self, binary_path: str, additional_args: List[str] = None) -> str:
        """
        Run ghidra-cli on the specified binary
        
        Args:
            binary_path: Path to the binary to disassemble
            additional_args: Additional arguments for ghidra-cli
            
        Returns:
            Raw output from ghidra-cli
        """
        cmd = [self.ghidra_path, binary_path]
        
        # Add common ghidra-cli arguments for full disassembly
        cmd.extend([
            "--decompile",  # Get decompiled C code
            "--symbols",    # Export symbols
            "--strings",    # Extract strings
            "--functions",  # List all functions
            "--format", "json"  # Get structured output if supported
        ])
        
        if additional_args:
            cmd.extend(additional_args)
        
        print(f"Running command: {' '.join(cmd)}")
        
        try:
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                check=True
            )
            return result.stdout
        except subprocess.CalledProcessError as e:
            print(f"Error running ghidra-cli: {e}")
            print(f"Stderr: {e.stderr}")
            # Try simpler command if the above fails
            cmd = [self.ghidra_path, binary_path, "--decompile"]
            result = subprocess.run(cmd, capture_output=True, text=True)
            return result.stdout
        except FileNotFoundError:
            print(f"ghidra-cli not found at {self.ghidra_path}")
            print("Please install ghidra-cli: pip install ghidra-cli")
            sys.exit(1)
    
    def separate_code_and_data(self, ghidra_output: str) -> Tuple[str, str]:
        """
        Separate the ghidra output into code and data sections
        
        Args:
            ghidra_output: Raw output from ghidra-cli
            
        Returns:
            Tuple of (code_content, data_content)
        """
        code_content = []
        data_content = []
        
        # Patterns to identify different sections
        code_patterns = [
            r'^\s*\/\*.*\*\/',  # C-style comments
            r'^\s*\w+\s+\w+\s*\([^)]*\)\s*{',  # Function definitions
            r'^\s*(if|while|for|switch|return|break|continue)',  # Control flow
            r'^\s*\w+\s*=',  # Assignments
            r'^\s*}',  # Closing braces
            r'^FUN_',  # Ghidra function names
            r'^LAB_',  # Ghidra labels
        ]
        
        data_patterns = [
            r'^\.data',  # Data section marker
            r'^\.rodata',  # Read-only data
            r'^\.bss',  # BSS section
            r'^\s*DAT_',  # Ghidra data labels
            r'^\s*PTR_',  # Pointer data
            r'^\s*s_',  # String data
            r'^\s*0x[0-9a-fA-F]+:',  # Memory addresses with data
            r'^\s*\.[a-z]+\s+',  # Assembly directives
        ]
        
        lines = ghidra_output.split('\n')
        current_section = 'unknown'
        
        for line in lines:
            # Check if line matches code patterns
            is_code = any(re.match(pattern, line) for pattern in code_patterns)
            # Check if line matches data patterns
            is_data = any(re.match(pattern, line) for pattern in data_patterns)
            
            # Heuristic: function decompilation usually has indentation
            if not is_code and not is_data:
                if line.strip() and (line.startswith('    ') or line.startswith('\t')):
                    is_code = True
            
            if is_code:
                code_content.append(line)
                current_section = 'code'
            elif is_data:
                data_content.append(line)
                current_section = 'data'
            else:
                # Add to current section if unclear
                if current_section == 'code':
                    code_content.append(line)
                elif current_section == 'data':
                    data_content.append(line)
                else:
                    # Default to code for unknown lines
                    code_content.append(line)
        
        return '\n'.join(code_content), '\n'.join(data_content)
    
    def save_to_files(self, code_content: str, data_content: str, 
                     base_name: str = "disassembly") -> Tuple[str, str]:
        """
        Save code and data content to separate files
        
        Args:
            code_content: Decompiled C code
            data_content: Data section content
            base_name: Base name for output files
            
        Returns:
            Tuple of (code_file_path, data_file_path)
        """
        # Create output directory if it doesn't exist
        output_dir = Path("ghidra_output")
        output_dir.mkdir(exist_ok=True)
        
        # Save C code
        code_file = output_dir / f"{base_name}_code.c"
        with open(code_file, 'w') as f:
            f.write("/* Decompiled C code from Ghidra */\n\n")
            f.write(code_content)
        
        # Save data section
        data_file = output_dir / f"{base_name}_data.txt"
        with open(data_file, 'w') as f:
            f.write("# Data section from Ghidra\n\n")
            f.write(data_content)
        
        print(f"Saved code to: {code_file}")
        print(f"Saved data to: {data_file}")
        
        return str(code_file), str(data_file)
    
    def chunk_content(self, content: str, chunk_type: str) -> List[DisassemblyChunk]:
        """
        Split content into chunks suitable for LLM processing
        
        Args:
            content: Content to chunk
            chunk_type: Type of content ('code' or 'data')
            
        Returns:
            List of DisassemblyChunk objects
        """
        chunks = []
        lines = content.split('\n')
        current_chunk = []
        current_size = 0
        chunk_index = 0
        
        # Estimate 4 characters per token (rough approximation)
        chars_per_token = 4
        max_chars = self.max_chunk_size * chars_per_token
        
        for line in lines:
            line_size = len(line)
            
            # Check if adding this line would exceed chunk size
            if current_size + line_size > max_chars and current_chunk:
                # Save current chunk
                chunk_content = '\n'.join(current_chunk)
                chunks.append(DisassemblyChunk(
                    content=chunk_content,
                    chunk_type=chunk_type,
                    chunk_index=chunk_index
                ))
                chunk_index += 1
                current_chunk = [line]
                current_size = line_size
            else:
                current_chunk.append(line)
                current_size += line_size
        
        # Add remaining content
        if current_chunk:
            chunk_content = '\n'.join(current_chunk)
            chunks.append(DisassemblyChunk(
                content=chunk_content,
                chunk_type=chunk_type,
                chunk_index=chunk_index
            ))
        
        return chunks
    
    def analyze_with_llm(self, chunk: DisassemblyChunk, 
                        analysis_prompt: str = None) -> str:
        """
        Send a chunk to Anthropic API for analysis
        
        Args:
            chunk: DisassemblyChunk to analyze
            analysis_prompt: Custom prompt for analysis
            
        Returns:
            LLM analysis response
        """
        if not analysis_prompt:
            if chunk.chunk_type == 'code':
                analysis_prompt = """Analyze this decompiled C code from Ghidra. 
                Identify:
                1. Main functionality and purpose
                2. Potential vulnerabilities or security issues
                3. Interesting algorithms or logic patterns
                4. Suggestions for improvement or understanding"""
            else:
                analysis_prompt = """Analyze this data section from a disassembled binary.
                Identify:
                1. Data structures and their purposes
                2. Strings and their potential uses
                3. Memory layout patterns
                4. Interesting constants or addresses"""
        
        prompt = f"""{analysis_prompt}

Chunk Type: {chunk.chunk_type}
Chunk Index: {chunk.chunk_index}

Content:
```
{chunk.content}
```
"""
        
        try:
            response = self.client.messages.create(
                model="claude-3-5-sonnet-20241022",
                max_tokens=4000,
                temperature=0,
                messages=[
                    {"role": "user", "content": prompt}
                ]
            )
            return response.content[0].text
        except Exception as e:
            print(f"Error calling Anthropic API: {e}")
            return f"Error analyzing chunk: {str(e)}"
    
    def process_binary(self, binary_path: str, 
                       analysis_prompt: str = None,
                       save_analysis: bool = True) -> Dict:
        """
        Complete pipeline: disassemble, separate, chunk, and analyze
        
        Args:
            binary_path: Path to binary file
            analysis_prompt: Custom analysis prompt
            save_analysis: Whether to save analysis results
            
        Returns:
            Dictionary with results
        """
        print(f"Processing binary: {binary_path}")
        base_name = Path(binary_path).stem
        
        # Step 1: Run Ghidra
        print("Running Ghidra disassembly...")
        ghidra_output = self.run_ghidra_cli(binary_path)
        
        # Step 2: Separate code and data
        print("Separating code and data sections...")
        code_content, data_content = self.separate_code_and_data(ghidra_output)
        
        # Step 3: Save to files
        code_file, data_file = self.save_to_files(code_content, data_content, base_name)
        
        # Step 4: Create chunks
        print("Creating chunks for LLM processing...")
        code_chunks = self.chunk_content(code_content, 'code')
        data_chunks = self.chunk_content(data_content, 'data')
        
        print(f"Created {len(code_chunks)} code chunks and {len(data_chunks)} data chunks")
        
        # Step 5: Analyze with LLM
        print("Analyzing with LLM...")
        analyses = []
        
        # Analyze code chunks
        for i, chunk in enumerate(code_chunks):
            print(f"Analyzing code chunk {i+1}/{len(code_chunks)}...")
            analysis = self.analyze_with_llm(chunk, analysis_prompt)
            analyses.append({
                'type': 'code',
                'chunk_index': i,
                'analysis': analysis
            })
        
        # Analyze data chunks
        for i, chunk in enumerate(data_chunks):
            print(f"Analyzing data chunk {i+1}/{len(data_chunks)}...")
            analysis = self.analyze_with_llm(chunk, analysis_prompt)
            analyses.append({
                'type': 'data',
                'chunk_index': i,
                'analysis': analysis
            })
        
        # Save analysis results to storage folder
        if save_analysis:
            # Get storage directory (same logic as save_to_files)
            current_dir = Path(__file__).parent
            if current_dir.name == 'backend':
                storage_dir = current_dir.parent / 'storage'
            else:
                storage_dir = Path('../storage').resolve()
                if not storage_dir.exists():
                    storage_dir = current_dir.parent / 'storage'
            
            storage_dir.mkdir(exist_ok=True, parents=True)
            analysis_file = storage_dir / f"{base_name}_analysis.json"
            
            with open(analysis_file, 'w') as f:
                json.dump(analyses, f, indent=2)
            print(f"Saved analysis to: {analysis_file}")
        
        return {
            'code_file': code_file,
            'data_file': data_file,
            'code_chunks': len(code_chunks),
            'data_chunks': len(data_chunks),
            'analyses': analyses
        }

def main():
    parser = argparse.ArgumentParser(description='LLM-assisted Ghidra disassembly program')
    parser.add_argument('binary', help='Path to binary file to analyze')
    parser.add_argument('--api-key', required=True, help='Anthropic API key')
    parser.add_argument('--ghidra-path', default='ghidra-cli', 
                       help='Path to ghidra-cli executable')
    parser.add_argument('--prompt', help='Custom analysis prompt for LLM')
    parser.add_argument('--no-save-analysis', action='store_true',
                       help='Do not save analysis results')
    
    args = parser.parse_args()
    
    # Create assistant instance
    assistant = GhidraLLMAssistant(
        api_key=args.api_key,
        ghidra_path=args.ghidra_path
    )
    
    # Process the binary
    results = assistant.process_binary(
        binary_path=args.binary,
        analysis_prompt=args.prompt,
        save_analysis=not args.no_save_analysis
    )
    
    # Print summary
    print("\n=== Processing Complete ===")
    print(f"Code file: {results['code_file']}")
    print(f"Data file: {results['data_file']}")
    print(f"Code chunks analyzed: {results['code_chunks']}")
    print(f"Data chunks analyzed: {results['data_chunks']}")

if __name__ == "__main__":
    main()