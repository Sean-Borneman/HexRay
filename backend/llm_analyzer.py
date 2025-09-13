#!/usr/bin/env python3
"""
LLM Analyzer Module
Handles chunking and analysis of disassembled code using Anthropic's API
"""

import json
import os
import sys
import getpass
from pathlib import Path
from typing import List, Dict, Optional
from dataclasses import dataclass
import anthropic
from anthropic import Anthropic

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
    def __init__(self, api_key: str = None, model: str = "claude-3-5-sonnet-20241022"):
        """
        Initialize the LLM Analyzer
        
        Args:
            api_key: Anthropic API key (optional, can use env var)
            model: Model to use for analysis
        """
        self.api_key = self._get_api_key(api_key)
        self.client = Anthropic(api_key=self.api_key)
        self.model = model
        self.max_chunk_size = 8000  # Max tokens per chunk
        self.storage_dir = self._get_storage_dir()
    
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
    
    def _get_api_key(self, provided_key: str = None) -> str:
        """
        Get API key from various sources
        
        Args:
            provided_key: Directly provided API key
            
        Returns:
            Valid API key
        """
        # Priority order: provided key, env var, config file
        if provided_key:
            return provided_key
        
        # Check environment variable
        if os.environ.get('ANTHROPIC_API_KEY'):
            return os.environ.get('ANTHROPIC_API_KEY')
        
        # Check config file
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
                    custom_prompt: str = None) -> List[AnalysisResult]:
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
        
        # Create chunks
        chunks = self.chunk_content(content, file_type)
        print(f"Created {len(chunks)} chunks for analysis")
        
        # Analyze each chunk
        results = []
        for chunk in chunks:
            print(f"Analyzing {file_type} chunk {chunk.chunk_index + 1}/{len(chunks)}...")
            result = self.analyze_chunk(chunk, custom_prompt)
            results.append(result)
        
        return results
    
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

def main():
    """Standalone usage of LLM analyzer"""
    import argparse
    
    parser = argparse.ArgumentParser(description='LLM Code Analyzer')
    parser.add_argument('file', help='Path to file to analyze')
    parser.add_argument('--type', choices=['code', 'data'], default='code',
                       help='Type of file to analyze')
    parser.add_argument('--api-key', help='Anthropic API key')
    parser.add_argument('--prompt', help='Custom analysis prompt')
    parser.add_argument('--model', default='claude-3-5-sonnet-20241022',
                       help='Model to use for analysis')
    
    args = parser.parse_args()
    
    analyzer = LLMAnalyzer(api_key=args.api_key, model=args.model)
    
    # Analyze file
    results = analyzer.analyze_file(
        file_path=args.file,
        file_type=args.type,
        custom_prompt=args.prompt
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

if __name__ == "__main__":
    main()