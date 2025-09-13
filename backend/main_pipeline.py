#!/usr/bin/env python3
"""
Main Pipeline Script
Orchestrates the complete Ghidra disassembly and LLM analysis pipeline
"""

import argparse
import json
import sys
from pathlib import Path
from typing import Dict, Optional

# Import the separate modules
from ghidra_processor import GhidraProcessor, ProcessedBinary
from llm_analyzer import LLMAnalyzer, AnalysisResult

class DisassemblyPipeline:
    def __init__(self, ghidra_path: str = "ghidra-cli", 
                 api_key: str = None,
                 model: str = "claude-3-5-sonnet-20241022"):
        """
        Initialize the complete pipeline
        
        Args:
            ghidra_path: Path to ghidra-cli executable
            api_key: Anthropic API key
            model: LLM model to use
        """
        self.ghidra_processor = GhidraProcessor(ghidra_path=ghidra_path)
        self.llm_analyzer = LLMAnalyzer(api_key=api_key, model=model)
        self.storage_dir = self.ghidra_processor.storage_dir
    
    def run_pipeline(self, binary_path: str, 
                    analyze_code: bool = True,
                    analyze_data: bool = True,
                    custom_prompt: str = None,
                    generate_summary: bool = True) -> Dict:
        """
        Run the complete disassembly and analysis pipeline
        
        Args:
            binary_path: Path to binary file
            analyze_code: Whether to analyze code sections
            analyze_data: Whether to analyze data sections
            custom_prompt: Custom prompt for LLM analysis
            generate_summary: Whether to generate a final summary
            
        Returns:
            Dictionary with all results and paths
        """
        print("=" * 60)
        print("Starting Disassembly and Analysis Pipeline")
        print("=" * 60)
        
        # Step 1: Process with Ghidra
        print("\n[Step 1/4] Processing binary with Ghidra...")
        processed = self.ghidra_processor.process_binary(binary_path)
        
        all_results = []
        
        # Step 2: Analyze code if requested
        if analyze_code and processed.code_content:
            print("\n[Step 2/4] Analyzing code sections...")
            code_results = self.llm_analyzer.analyze_file(
                file_path=processed.code_file_path,
                file_type='code',
                custom_prompt=custom_prompt
            )
            all_results.extend(code_results)
        else:
            print("\n[Step 2/4] Skipping code analysis")
            code_results = []
        
        # Step 3: Analyze data if requested
        if analyze_data and processed.data_content:
            print("\n[Step 3/4] Analyzing data sections...")
            data_results = self.llm_analyzer.analyze_file(
                file_path=processed.data_file_path,
                file_type='data',
                custom_prompt=custom_prompt
            )
            all_results.extend(data_results)
        else:
            print("\n[Step 3/4] Skipping data analysis")
            data_results = []
        
        # Step 4: Generate summary if requested
        summary = None
        if generate_summary and all_results:
            print("\n[Step 4/4] Generating comprehensive summary...")
            summary = self.llm_analyzer.generate_summary(all_results)
            
            # Save summary
            summary_file = self.storage_dir / f"{processed.binary_name}_summary.txt"
            with open(summary_file, 'w') as f:
                f.write(summary)
            print(f"Saved summary to: {summary_file}")
        else:
            print("\n[Step 4/4] Skipping summary generation")
        
        # Save all analysis results
        if all_results:
            analysis_file = self.llm_analyzer.save_analysis(
                all_results, 
                processed.binary_name
            )
        else:
            analysis_file = None
        
        # Create final results dictionary
        results = {
            'binary_name': processed.binary_name,
            'code_file': processed.code_file_path,
            'data_file': processed.data_file_path,
            'analysis_file': analysis_file,
            'summary_file': str(self.storage_dir / f"{processed.binary_name}_summary.txt") if summary else None,
            'code_chunks_analyzed': len(code_results),
            'data_chunks_analyzed': len(data_results),
            'total_chunks': len(all_results),
            'tokens_used': sum(r.tokens_used for r in all_results)
        }
        
        # Save pipeline results
        results_file = self.storage_dir / f"{processed.binary_name}_pipeline_results.json"
        with open(results_file, 'w') as f:
            json.dump(results, f, indent=2)
        
        return results
    
    def print_results(self, results: Dict):
        """
        Print formatted results summary
        
        Args:
            results: Results dictionary from pipeline
        """
        print("\n" + "=" * 60)
        print("PIPELINE COMPLETE - RESULTS SUMMARY")
        print("=" * 60)
        print(f"Binary Name: {results['binary_name']}")
        print(f"Code File: {results['code_file']}")
        print(f"Data File: {results['data_file']}")
        
        if results['analysis_file']:
            print(f"Analysis File: {results['analysis_file']}")
        
        if results['summary_file']:
            print(f"Summary File: {results['summary_file']}")
        
        print(f"\nChunks Analyzed:")
        print(f"  - Code: {results['code_chunks_analyzed']}")
        print(f"  - Data: {results['data_chunks_analyzed']}")
        print(f"  - Total: {results['total_chunks']}")
        
        if results['tokens_used']:
            print(f"\nTotal Tokens Used: {results['tokens_used']:,}")
        
        print("\nAll files saved to: {}".format(
            self.storage_dir.absolute()
        ))
        print("=" * 60