import subprocess
import os
import time
import sys
import re
import json
import shutil
from pathlib import Path
from ghidraDecompileTWOFiles import export_consolidated_code_and_data
from llm_analyzer import LLMAnalyzer
# from ghidraDecompileToText import export_with_pyghidra

# --- Helpers for optional automated hacking stage ---
def _wait_for_server_signal(flag_path: Path, env_var: str = 'AUTO_HACK_NOW', timeout: int = 600, poll: float = 1.0) -> bool:
    """Wait for a go-signal from server.js.

    Signal sources:
      - Environment variable env_var set to truthy (e.g., 1, true)
      - A flag file created at flag_path
    Returns True if signaled within timeout; False otherwise.
    """
    truthy = {"1", "true", "yes", "on"}
    if str(os.getenv(env_var, "")).strip().lower() in truthy:
        return True
    start = time.time()
    while time.time() - start < timeout:
        if flag_path.exists():
            return True
        time.sleep(poll)
    return False


def _find_original_executable(upload_root: Path) -> Path | None:
    """Find the most recent file under storage/uploads (recursively)."""
    if not upload_root.exists():
        return None
    files = [p for p in upload_root.rglob('*') if p.is_file()]
    if not files:
        return None
    files.sort(key=lambda p: p.stat().st_mtime, reverse=True)
    return files[0]

def _rm_tree_contents(root: Path):
    try:
        if not root.exists():
            return
        for child in root.iterdir():
            try:
                if child.is_dir():
                    shutil.rmtree(child, ignore_errors=True)
                else:
                    try:
                        child.unlink(missing_ok=True)  # py3.8+: ignore errors below
                    except TypeError:
                        # Fallback for older Python
                        if child.exists():
                            child.unlink()
            except Exception:
                pass
    except Exception:
        pass

def _pre_run_cleanup():
    """Remove artifacts from previous runs before starting a new one.

    Preserves uploads, deletes analysis outputs:
      - ./ghidra_projects (entire tree)
      - ./decompiled_output (entire tree)
      - ./storage/working (contents)
      - ./storage/results (contents)
    """
    try:
        print("[Cleanup] Removing previous analysis artifacts...")
        shutil.rmtree(Path('./ghidra_projects'), ignore_errors=True)
        shutil.rmtree(Path('./decompiled_output'), ignore_errors=True)
        _rm_tree_contents(Path('./storage/working'))
        _rm_tree_contents(Path('./storage/results'))
        # Ensure directories exist after cleanup
        Path('./storage/working').mkdir(parents=True, exist_ok=True)
        Path('./storage/results').mkdir(parents=True, exist_ok=True)
        print("[Cleanup] Done.")
    except Exception as e:
        print(f"[Cleanup] Warning: cleanup encountered an issue: {e}")
class SimpleGhidraCLI:
    def __init__(self):
        self.script_path = Path("./ghidra-cli").resolve()
        self.git_bash = self._find_git_bash()
    

    def _find_git_bash(self):
        """Find Git Bash executable"""
        possible_paths = [
            r"C:\Program Files\Git\bin\bash.exe",
            r"C:\Program Files (x86)\Git\bin\bash.exe",
            r"C:\Git\bin\bash.exe"
        ]
        
        for path in possible_paths:
            if Path(path).exists():
                return path
        
        raise FileNotFoundError("Git Bash not found. Please install Git for Windows.")
    
    def run(self, args, cwd=None):
        """Run ghidra-cli using bash -c"""
        # Create the command as a string
        script_name = self.script_path.name
        bash_args = " ".join(f'"{arg}"' for arg in args)
        
        if cwd:
            # Change to the directory first, then run the script
            bash_command = f'cd "{cwd}" && bash "{script_name}" {bash_args}'
            working_dir = None  # Let bash handle the directory change
        else:
            bash_command = f'bash "{script_name}" {bash_args}'
            working_dir = self.script_path.parent
        
        cmd = [self.git_bash, "-c", bash_command]
        
        try:
            print(f"Running: {bash_command}")
            result = subprocess.run(
                cmd,
                cwd=working_dir,
                capture_output=True,
                text=True,
                check=True
            )
            return result
        except subprocess.CalledProcessError as e:
            print(f"Command failed: {bash_command}")
            print(f"Error: {e.stderr}")
            print(f"Output: {e.stdout}")
            raise
    
    def analyze_binary(self, binary_path, project_name=None, project_dir=None):
        """Analyze a binary file with stoghidra-cli"""
        # Check if binary exists
        binary_file = Path(binary_path)
        if not binary_file.exists():
            raise FileNotFoundError(f"Binary file not found: {binary_file.resolve()}")
        # Build arguments for ghidra-cli
        args = ['-n', '-i', str(binary_path)]
        
        if project_dir:
            args.extend(['-d', str(project_dir)])
        
        if project_name:
            args.extend(['--name', project_name])
        
        print(f"Starting analysis of: {binary_file.resolve()}")
        print(f"Project will be created in: {project_dir or '/tmp'}")
        print(f"Project name:5 {project_name or 'auto-generated'}")
        print("This may take a while for large binaries...")
        
        try:
            result = self.run(args)
            print("Analysis completed successfully!")
            print("Output:", result.stdout)
            return result
        except Exception as e:
            print(f"Analysis failed: {e}")
            raise

def main():
    try:
        ghidra = SimpleGhidraCLI()
        
        storage_dir = Path("./storage/uploads")
        
        if not storage_dir.exists():
            print(f"Storage folder not found: {storage_dir.resolve()}")
            print("Please create a 'storage' folder and put your binary file in it.")
            return
        
        # Get the first file in storage folder
        files = [f for f in storage_dir.iterdir() if f.is_file()]
        
        if not files:
            print(f"No files found in storage folder: {storage_dir.resolve()}")
            print("Please put a binary file in the storage folder.")
            return
        
        # Use the first file found
        binary_file = files[0]
        
        # Set up paths based on the file found
        binary_path = str(binary_file)
        project_name = f"{binary_file.stem}_analysis"  # e.g., "myfile_analysis"
        project_dir = "./ghidra_projects"  # Optional: specify where to save the project
        
        # Check if the binary exists first
        if not Path(binary_path).exists():
            print(f"Binary file '{binary_path}' not found in current directory.")
            print(f"Current directory: {Path.cwd()}")
            print("Files in current directory:")
            for file in Path.cwd().iterdir():
                if file.is_file():
                    print(f"  - {file.name}")
            return
        
        # Create project directory if specified
        if project_dir:
            Path(project_dir).mkdir(exist_ok=True)
        
        # Run the analysis
        result = ghidra.analyze_binary(
            binary_path=binary_path,
            project_name=project_name,
            project_dir=project_dir
        )
        
        print(f"\nAnalysis complete! Project saved as '{project_name}'")
        if project_dir:
            print(f"Project location: {Path(project_dir).resolve()}")
        
    except FileNotFoundError as e:
        print(f"Setup Error: {e}")
    except subprocess.CalledProcessError as e:
        print(f"Execution Error: {e}")
    except Exception as e:
        print(f"Unexpected Error: {e}")

if __name__ == "__main__":
    # Always clean stale artifacts before starting a new run
    _pre_run_cleanup()
    main()
    # export_with_pyghidra()
    
    export_consolidated_code_and_data()

    # After consolidated export, automatically run LLM typing + summary
    try:
        funcs_path = Path('./decompiled_output/ALL_FUNCTIONS.c')
        data_path = Path('./decompiled_output/ALL_DATA.txt')
        if not funcs_path.exists():
            print("[LLM] Skipping typing: consolidated file ./decompiled_output/ALL_FUNCTIONS.c not found.")
            raise SystemExit(0)

        print("[LLM] Running typing and summarization on consolidated outputs...")
        analyzer = LLMAnalyzer()
        print(f"[LLM] Using model: {analyzer.model}")
        if getattr(analyzer, 'client', None) is None:
            print("[LLM] Anthropic client is not initialized. Ensure the 'anthropic' package is installed in this Python and your API key is configured.")

        outputs = analyzer.annotate_types_and_summarize(
            c_file_path=str(funcs_path),
            objdump_path=str(data_path) if data_path.exists() else None,
            out_ext='c'
        )

        typed_path = Path(outputs.get('typed_code_file') or '')
        summary_path = Path(outputs.get('summary_file') or '')
        combined_path = Path(outputs.get('combined_input_file') or '')

        print("[LLM] Typed code:", str(typed_path) if typed_path else 'N/A')
        print("[LLM] Summary:", str(summary_path) if summary_path else 'N/A')
        if combined_path:
            try:
                csz = combined_path.stat().st_size
                print(f"[LLM] Combined input: {combined_path} (size: {csz:,} bytes)")
            except Exception:
                print(f"[LLM] Combined input: {combined_path}")

        # Diagnose unchanged typed output
        try:
            if typed_path and typed_path.exists():
                original_c = funcs_path.read_text(errors='ignore')
                typed_c = typed_path.read_text(errors='ignore')
                if original_c.strip() == typed_c.strip():
                    print("[LLM][Diag] Typed C appears unchanged from input. Possible reasons:")
                    print(" - Offline fallback due to missing SDK, invalid API key, or network issues")
                    print(" - Model error (e.g., unsupported model) or request too large for context window")
                    print(" - The model chose not to modify types (rare)")
        except Exception as e:
            print(f"[LLM][Diag] Could not compare typed C with original: {e}")

        # Diagnose empty or fallback summary
        try:
            if summary_path and summary_path.exists():
                summary_text = summary_path.read_text(errors='ignore')
                if not summary_text.strip() or 'No summary generated.' in summary_text:
                    print("[LLM][Diag] Summary is empty. Potential causes: API error or oversized prompt.")
                if 'Offline fallback:' in summary_text:
                    print("[LLM][Diag] Summary indicates offline fallback. Check console for [LLMAnalyzer] errors above.")
                # Surface embedded LLM error line if present
                for line in summary_text.splitlines():
                    if line.startswith('LLM error:'):
                        print(f"[LLM][Diag] {line}")
                        break
        except Exception as e:
            print(f"[LLM][Diag] Could not inspect summary file: {e}")

        # ---- Optional automated hacking stage (gated by server signal) ----
        try:
            signal_path = Path('./storage/working/enable_auto_hack.flag')
            env_val = os.getenv('AUTO_HACK_NOW')
            print(f"[AutoHack] Waiting for server signal (env AUTO_HACK_NOW=1 or {signal_path})...")
            # If explicitly disabled, skip without waiting
            if isinstance(env_val, str) and env_val.strip().lower() in {"0","false","no","off"}:
                print("[AutoHack] AUTO_HACK_NOW explicitly disabled; skipping automated hacking.")
            elif _wait_for_server_signal(signal_path, env_var='AUTO_HACK_NOW', timeout=600, poll=1.0):
                print("[AutoHack] Signal received. Running automated hacking steps...")
                # Determine inputs
                combined_candidates = [
                    combined_path if combined_path and combined_path.exists() else None,
                    Path('./storage/working_combined.txt') if Path('./storage/working_combined.txt').exists() else None,
                ]
                chosen_combined = next((p for p in combined_candidates if p), None)
                if not chosen_combined:
                    print("[AutoHack] No combined input found. Skipping automated hacking.")
                else:
                    # Import local modules lazily
                    from automatedhacking.findvulnerabilities import find_vulnerabilities
                    from automatedhacking.generateexploit import generate_exploit

                    results_dir = Path('./storage/results')
                    results_dir.mkdir(parents=True, exist_ok=True)

                    # Step 1: static heuristics to extract vulns and payloads
                    fv = find_vulnerabilities(
                        combined_path=str(chosen_combined),
                        typed_c_path=str(typed_path) if typed_path and typed_path.exists() else None,
                        summary_path=str(summary_path) if summary_path and summary_path.exists() else None,
                        out_dir=str(results_dir),
                    )

                    # Step 2: generate exploit runner scaffold
                    exe = _find_original_executable(Path('./storage/uploads'))
                    if not exe:
                        print("[AutoHack] Could not locate original executable under storage/uploads. Skipping exploit generation.")
                    else:
                        # Allow frontend to provide custom flag regex via env
                        flag_regex = os.getenv('FLAG_REGEX') or r"FortID\{[^}]+\}"
                        ge = generate_exploit(
                            vulnerabilities_json=fv.get('vulnerabilities'),
                            typed_c_path=str(typed_path) if typed_path and typed_path.exists() else None,
                            original_exe=str(exe),
                            out_dir=str(results_dir),
                            flag_regex=flag_regex,
                            combined_path=str(chosen_combined) if chosen_combined else None,
                        )
                        print(f"[AutoHack] Exploit generated and executed: {ge.get('exploit_script')}")
            else:
                print("[AutoHack] No signal received within timeout. Skipping automated hacking.")
        except Exception as e:
            print(f"[AutoHack] Error during automated hacking stage: {e}")

    except Exception as e:
        print(f"[LLM] Error during typing/summarization: {e}")
