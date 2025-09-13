#!/usr/bin/env python3
"""
Ghidra Processor Module
Handles Ghidra CLI operations: disassembly, code/data separation, and file storage
"""

import subprocess
import re
import sys
import json
from pathlib import Path
from typing import Tuple, List, Optional, Dict
from dataclasses import dataclass, asdict

@dataclass
class ProcessedBinary:
    """Container for processed binary data"""
    code_content: str
    data_content: str
    code_file_path: str
    data_file_path: str
    binary_name: str
    ghidra_raw_output: str
    
    def to_dict(self) -> Dict:
        """Convert to dictionary for JSON serialization"""
        return {
            'code_file_path': self.code_file_path,
            'data_file_path': self.data_file_path,
            'binary_name': self.binary_name,
            'code_length': len(self.code_content),
            'data_length': len(self.data_content)
        }

class GhidraProcessor:
    def __init__(self, ghidra_path: str = "ghidra-cli"):
        """
        Initialize the Ghidra Processor
        
        Args:
            ghidra_path: Path to ghidra-cli executable
        """
        self.ghidra_path = ghidra_path
        self.storage_dir = self._get_storage_dir()
        
    def _get_storage_dir(self) -> Path:
        """Get or create the storage directory"""
        current_dir = Path(__file__).parent
        
        if current_dir.name == 'backend':
            storage_dir = current_dir.parent / 'storage'
        else:
            storage_dir = Path('../storage').resolve()
            if not storage_dir.exists():
                storage_dir = current_dir.parent / 'storage'
        
        storage_dir.mkdir(exist_ok=True, parents=True)
        return storage_dir
    
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
                     base_name: str) -> Tuple[str, str]:
        """
        Save code and data content to separate files in storage directory
        
        Args:
            code_content: Decompiled C code
            data_content: Data section content
            base_name: Base name for output files
            
        Returns:
            Tuple of (code_file_path, data_file_path)
        """
        # Save C code
        code_file = self.storage_dir / f"{base_name}_code.c"
        with open(code_file, 'w') as f:
            f.write("/* Decompiled C code from Ghidra */\n\n")
            f.write(code_content)
        
        # Save data section
        data_file = self.storage_dir / f"{base_name}_data.txt"
        with open(data_file, 'w') as f:
            f.write("# Data section from Ghidra\n\n")
            f.write(data_content)
        
        print(f"Saved code to: {code_file}")
        print(f"Saved data to: {data_file}")
        
        return str(code_file), str(data_file)
    
    def process_binary(self, binary_path: str) -> ProcessedBinary:
        """
        Complete Ghidra processing pipeline
        
        Args:
            binary_path: Path to binary file
            
        Returns:
            ProcessedBinary object with all results
        """
        print(f"Processing binary with Ghidra: {binary_path}")
        base_name = Path(binary_path).stem
        
        # Run Ghidra
        print("Running Ghidra disassembly...")
        ghidra_output = self.run_ghidra_cli(binary_path)
        
        # Separate code and data
        print("Separating code and data sections...")
        code_content, data_content = self.separate_code_and_data(ghidra_output)
        
        # Save to files
        code_file, data_file = self.save_to_files(code_content, data_content, base_name)
        
        # Create result object
        result = ProcessedBinary(
            code_content=code_content,
            data_content=data_content,
            code_file_path=code_file,
            data_file_path=data_file,
            binary_name=base_name,
            ghidra_raw_output=ghidra_output
        )
        
        # Save metadata
        metadata_file = self.storage_dir / f"{base_name}_metadata.json"
        with open(metadata_file, 'w') as f:
            json.dump(result.to_dict(), f, indent=2)
        print(f"Saved metadata to: {metadata_file}")
        
        return result

def main():
    """Standalone usage of Ghidra processor"""
    import argparse
    
    parser = argparse.ArgumentParser(description='Ghidra CLI Processor')
    parser.add_argument('binary', help='Path to binary file to process')
    parser.add_argument('--ghidra-path', default='ghidra-cli',
                       help='Path to ghidra-cli executable')
    
    args = parser.parse_args()
    
    processor = GhidraProcessor(ghidra_path=args.ghidra_path)
    result = processor.process_binary(args.binary)
    
    print("\n=== Ghidra Processing Complete ===")
    print(f"Binary name: {result.binary_name}")
    print(f"Code file: {result.code_file_path}")
    print(f"Data file: {result.data_file_path}")
    print(f"Code size: {len(result.code_content)} bytes")
    print(f"Data size: {len(result.data_content)} bytes")

if __name__ == "__main__":
    main()