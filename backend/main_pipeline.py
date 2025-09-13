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
        print("=" * 60)

def main():
    """Main entry point for the pipeline"""
    parser = argparse.ArgumentParser(
        description='Complete Ghidra Disassembly and LLM Analysis Pipeline',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Basic usage (analyzes everything)
  python main_pipeline.py /path/to/binary

  # Only analyze code sections
  python main_pipeline.py binary.exe --no-data

  # Use custom prompt
  python main_pipeline.py binary --prompt "Focus on crypto functions"

  # Skip summary generation
  python main_pipeline.py binary --no-summary

  # Use specific model
  python main_pipeline.py binary --model claude-3-opus-20240229
        """
    )
    
    # Required arguments
    parser.add_argument('binary', help='Path to binary file to analyze')
    
    # Ghidra options
    parser.add_argument('--ghidra-path', default='ghidra-cli',
                       help='Path to ghidra-cli executable (default: ghidra-cli)')
    
    # API options
    parser.add_argument('--api-key', 
                       help='Anthropic API key (or set ANTHROPIC_API_KEY env var)')
    parser.add_argument('--model', default='claude-3-5-sonnet-20241022',
                       help='LLM model to use (default: claude-3-5-sonnet-20241022)')
    
    # Analysis options
    parser.add_argument('--no-code', action='store_true',
                       help='Skip code analysis')
    parser.add_argument('--no-data', action='store_true',
                       help='Skip data analysis')
    parser.add_argument('--no-summary', action='store_true',
                       help='Skip summary generation')
    parser.add_argument('--prompt', 
                       help='Custom prompt for LLM analysis')
    
    # Output options
    parser.add_argument('--quiet', action='store_true',
                       help='Minimal output')
    parser.add_argument('--verbose', action='store_true',
                       help='Verbose output')
    
    args = parser.parse_args()
    
    # Validate binary exists
    if not Path(args.binary).exists():
        print(f"Error: Binary file not found: {args.binary}")
        sys.exit(1)
    
    # Create pipeline
    try:
        pipeline = DisassemblyPipeline(
            ghidra_path=args.ghidra_path,
            api_key=args.api_key,
            model=args.model
        )
    except Exception as e:
        print(f"Error initializing pipeline: {e}")
        sys.exit(1)
    
    # Run pipeline
    try:
        results = pipeline.run_pipeline(
            binary_path=args.binary,
            analyze_code=not args.no_code,
            analyze_data=not args.no_data,
            custom_prompt=args.prompt,
            generate_summary=not args.no_summary
        )
        
        # Print results
        if not args.quiet:
            pipeline.print_results(results)
        
        # Exit successfully
        sys.exit(0)
        
    except KeyboardInterrupt:
        print("\n\nPipeline interrupted by user")
        sys.exit(130)
    except Exception as e:
        print(f"\nError during pipeline execution: {e}")
        if args.verbose:
            import traceback
            traceback.print_exc()
        sys.exit(1)

if __name__ == "__main__":
    main()