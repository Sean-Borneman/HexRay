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
                 model: str = "claude-sonnet-4-20250514",
                 disable_chunking: bool = True):
        """
        Initialize the complete pipeline
        
        Args:
            ghidra_path: Path to ghidra-cli executable
            api_key: Anthropic API key
            model: LLM model to use
        """
        self.ghidra_processor = GhidraProcessor(ghidra_path=ghidra_path)
        self.llm_analyzer = LLMAnalyzer(api_key=api_key, model=model, disable_chunking=disable_chunking)
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

    def run_from_files(self, c_file: str, objdump_file: Optional[str] = None) -> Dict:
        """
        Bypass Ghidra processing and operate directly on existing files.
        Produces typed C and a summary via LLM.

        Args:
            c_file: Path to decompiled C file to annotate
            objdump_file: Optional path to objdump/data text

        Returns:
            Dictionary with result file paths
        """
        print("=" * 60)
        print("Starting Analysis From Existing Files (No Ghidra)")
        print("=" * 60)

        outputs = self.llm_analyzer.annotate_types_and_summarize(
            c_file_path=c_file,
            objdump_path=objdump_file,
            out_ext='c'
        )

        results = {
            'binary_name': Path(c_file).stem,
            'code_file': c_file,
            'data_file': objdump_file,
            'analysis_file': None,
            'summary_file': outputs.get('summary_file'),
            'combined_input_file': outputs.get('combined_input_file'),
            'typed_code_file': outputs.get('typed_code_file'),
            'code_chunks_analyzed': 0,
            'data_chunks_analyzed': 0,
            'total_chunks': 0,
            'tokens_used': 0,
        }

        # Save pipeline results snapshot
        results_file = self.storage_dir / f"{Path(c_file).stem}_pipeline_results.json"
        with open(results_file, 'w') as f:
            json.dump(results, f, indent=2)

        return results

    def _combine_export_outputs(self, binary_stem: str) -> Optional[Dict[str, str]]:
        """Combine Ghidra export outputs into a single C file and a single data file.

        Looks for ./decompiled_output/{functions,data,strings,symbols} produced by
        ghidraWithDataCall.py and writes merged artifacts into storage/.

        Returns a dict with paths or None if exports not found.
        """
        export_root = Path('./decompiled_output')
        funcs_dir = export_root / 'functions'
        data_dir = export_root / 'data'
        strings_file = export_root / 'strings' / 'all_strings.txt'
        symbols_file = export_root / 'symbols' / 'all_symbols.txt'

        if not export_root.exists() or not funcs_dir.exists():
            return None

        merged_c = self.storage_dir / f"{binary_stem}_functions_merged.c"
        combined_data = self.storage_dir / f"{binary_stem}_export_data.txt"

        # Merge all function .c files
        try:
            with open(merged_c, 'w') as out_c:
                out_c.write(f"/* Merged functions for {binary_stem} */\n\n")
                for cpath in sorted(funcs_dir.glob('*.c')):
                    out_c.write(f"/* === BEGIN {cpath.name} === */\n")
                    try:
                        with open(cpath, 'r', errors='ignore') as f:
                            out_c.write(f.read())
                    except Exception:
                        pass
                    out_c.write(f"\n/* === END {cpath.name} === */\n\n")
        except Exception:
            return None

        # Combine data/strings/symbols into one text file (bounded merging handled downstream)
        try:
            with open(combined_data, 'w') as out_d:
                if data_dir.exists():
                    for dpath in sorted(data_dir.glob('*.txt')):
                        out_d.write(f"=== DATA FILE {dpath.name} START ===\n")
                        try:
                            with open(dpath, 'r', errors='ignore') as f:
                                out_d.write(f.read())
                        except Exception:
                            pass
                        out_d.write(f"\n=== DATA FILE {dpath.name} END ===\n\n")
                if strings_file.exists():
                    out_d.write("=== STRINGS START ===\n")
                    try:
                        with open(strings_file, 'r', errors='ignore') as f:
                            out_d.write(f.read())
                    except Exception:
                        pass
                    out_d.write("\n=== STRINGS END ===\n\n")
                if symbols_file.exists():
                    out_d.write("=== SYMBOLS START ===\n")
                    try:
                        with open(symbols_file, 'r', errors='ignore') as f:
                            out_d.write(f.read())
                    except Exception:
                        pass
                    out_d.write("\n=== SYMBOLS END ===\n")
        except Exception:
            return None

        return {
            'merged_c_file': str(merged_c),
            'combined_data_file': str(combined_data),
        }
    
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
        if results.get('combined_input_file'):
            print(f"Combined Input: {results['combined_input_file']}")
        if results.get('typed_code_file'):
            print(f"Typed Code File: {results['typed_code_file']}")
        
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
    parser.add_argument('binary', nargs='?', help='Path to binary file to analyze')
    
    # Ghidra options
    parser.add_argument('--ghidra-path', default='ghidra-cli',
                       help='Path to ghidra-cli executable (default: ghidra-cli)')
    
    # API options
    parser.add_argument('--api-key', 
                       help='Anthropic API key (or set ANTHROPIC_API_KEY env var)')
    parser.add_argument('--model', default='claude-sonnet-4-20250514',
                       help='LLM model to use (default: claude-sonnet-4-20250514)')
    
    # Analysis options
    parser.add_argument('--no-code', action='store_true',
                       help='Skip code analysis')
    parser.add_argument('--no-data', action='store_true',
                       help='Skip data analysis')
    parser.add_argument('--no-summary', action='store_true',
                       help='Skip summary generation')
    parser.add_argument('--prompt', 
                       help='Custom prompt for LLM analysis')
    parser.add_argument('--chunk', action='store_true',
                       help='Enable chunking (disabled by default)')

    # Alternate inputs / pipelines
    parser.add_argument('--c-file', help='Use existing decompiled C file (bypasses Ghidra)')
    parser.add_argument('--dump-file', help='Optional objdump/data file to aid typing')
    parser.add_argument('--use-ghirda-scripts', action='store_true',
                       help='Use ghirda-cli-call.py and ghidraDecompileToText.py instead of ghidra_processor')
    parser.add_argument('--use-ghidra-with-data', action='store_true',
                       help='Use ghidraWithDataCall.py as the first step to create a project and export code+data')
    
    # Output options
    parser.add_argument('--quiet', action='store_true',
                       help='Minimal output')
    parser.add_argument('--verbose', action='store_true',
                       help='Verbose output')
    
    args = parser.parse_args()
    
    # Validate mode selection
    using_existing = bool(args.c_file)
    if not using_existing and not args.binary and not args.use_ghirda_scripts and not args.use_ghidra_with_data:
        print("Error: provide a binary or --c-file or --use-ghirda-scripts or --use-ghidra-with-data")
        sys.exit(2)
    
    # Create pipeline
    try:
        pipeline = DisassemblyPipeline(
            ghidra_path=args.ghidra_path,
            api_key=args.api_key,
            model=args.model,
            disable_chunking=(not args.chunk)
        )
    except Exception as e:
        print(f"Error initializing pipeline: {e}")
        sys.exit(1)
    
    # Run pipeline
    try:
        if using_existing:
            # Operate directly on files in storage or user-provided paths
            c_path = args.c_file
            dump_path = args.dump_file
            if not Path(c_path).exists():
                print(f"Error: C file not found: {c_path}")
                sys.exit(1)
            if dump_path and not Path(dump_path).exists():
                print(f"Warning: dump file not found, continuing without it: {dump_path}")
                dump_path = None
            results = pipeline.run_from_files(c_file=c_path, objdump_file=dump_path)
        elif args.use_ghirda_scripts:
            # Run the alternate scripts to build a project and decompile to text
            import subprocess
            print("[Mode] Using ghirda-cli-call.py and ghidraDecompileTWOFiles.py")
            # First: run ghirda-cli-call.py (analyzes the first file in storage)
            try:
                subprocess.run([sys.executable, 'ghirda-cli-call.py'], check=True)
            except Exception as e:
                print(f"Error running ghirda-cli-call.py: {e}")
            # Second: run ghidraDecompileTWOFiles.py to export consolidated function C and data
            try:
                subprocess.run([sys.executable, 'ghidraDecompileTWOFiles.py'], check=True)
            except Exception as e:
                print(f"Error running ghidraDecompileTWOFiles.py: {e}")
            # If consolidated outputs exist, run typing/summarization automatically
            merged_c_path = Path('./decompiled_output/ALL_FUNCTIONS.c')
            combined_data_path = Path('./decompiled_output/ALL_DATA.txt')
            if merged_c_path.exists():
                outputs = pipeline.llm_analyzer.annotate_types_and_summarize(
                    c_file_path=str(merged_c_path),
                    objdump_path=str(combined_data_path) if combined_data_path.exists() else None,
                    out_ext='c'
                )
                results = {
                    'binary_name': merged_c_path.stem,
                    'code_file': str(merged_c_path),
                    'data_file': str(combined_data_path) if combined_data_path.exists() else None,
                    'analysis_file': None,
                    'summary_file': outputs.get('summary_file'),
                    'typed_code_file': outputs.get('typed_code_file'),
                    'combined_input_file': outputs.get('combined_input_file'),
                    'code_chunks_analyzed': 0,
                    'data_chunks_analyzed': 0,
                    'total_chunks': 0,
                    'tokens_used': 0,
                }
            else:
                print("Consolidated outputs not found; you can pass --c-file and --dump-file to run typing.")
                results = {
                    'binary_name': None,
                    'code_file': None,
                    'data_file': None,
                    'analysis_file': None,
                    'summary_file': None,
                    'typed_code_file': None,
                    'combined_input_file': None,
                    'code_chunks_analyzed': 0,
                    'data_chunks_analyzed': 0,
                    'total_chunks': 0,
                    'tokens_used': 0,
                }
        elif args.use_ghidra_with_data:
            # Create a Ghidra project from the provided binary and export code+data using pyghidra
            if not args.binary:
                print("Error: --use-ghidra-with-data requires a binary path.")
                sys.exit(2)
            if not Path(args.binary).exists():
                print(f"Error: Binary file not found: {args.binary}")
                sys.exit(1)
            from ghidraWithDataCall import export_code_and_data
            print("[Mode] Using ghidraWithDataCall.py to create project and export code+data")
            try:
                export_code_and_data(binary_path=args.binary)
            except Exception as e:
                print(f"Error running ghidraWithDataCall: {e}")
                if args.verbose:
                    import traceback
                    traceback.print_exc()
            # Combine exports into single C and data files, then run typing+summary via LLM
            binary_stem = Path(args.binary).stem
            merged = pipeline._combine_export_outputs(binary_stem)
            if not merged:
                print("Export finished, but could not find expected output directories. Skipping LLM step.")
                results = {
                    'binary_name': binary_stem,
                    'code_file': None,
                    'data_file': None,
                    'analysis_file': None,
                    'summary_file': None,
                    'typed_code_file': None,
                    'combined_input_file': None,
                    'code_chunks_analyzed': 0,
                    'data_chunks_analyzed': 0,
                    'total_chunks': 0,
                    'tokens_used': 0,
                }
            else:
                outputs = pipeline.llm_analyzer.annotate_types_and_summarize(
                    c_file_path=merged['merged_c_file'],
                    objdump_path=merged['combined_data_file'],
                    out_ext='c'
                )
                results = {
                    'binary_name': binary_stem,
                    'code_file': merged['merged_c_file'],
                    'data_file': merged['combined_data_file'],
                    'analysis_file': None,
                    'summary_file': outputs.get('summary_file'),
                    'typed_code_file': outputs.get('typed_code_file'),
                    'combined_input_file': outputs.get('combined_input_file'),
                    'code_chunks_analyzed': 0,
                    'data_chunks_analyzed': 0,
                    'total_chunks': 0,
                    'tokens_used': 0,
                }
        else:
            # Standard pipeline using ghidra_processor
            if not Path(args.binary).exists():
                print(f"Error: Binary file not found: {args.binary}")
                sys.exit(1)
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
