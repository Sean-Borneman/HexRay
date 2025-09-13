import subprocess
import os
from pathlib import Path
import shutil 
from ghidraDecompileTWOFiles import export_consolidated_code_and_data
# from ghidraDecompileToText import export_with_pyghidra
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
            print(f" Command failed: {bash_command}")
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
        
        print(f" Starting analysis of: {binary_file.resolve()}")
        print(f" Project will be created in: {project_dir or '/tmp'}")
        print(f" Project name:5 {project_name or 'auto-generated'}")
        print(" This may take a while for large binaries...")
        
        try:
            result = self.run(args)
            print("✅ Analysis completed successfully!")
            print("Output:", result.stdout)
            return result
        except Exception as e:
            print(f" Analysis failed: {e}")
            raise

def main():
    try:
        ghidra = SimpleGhidraCLI()
        
        storage_dir = Path("./storage/uploads")
        
        if not storage_dir.exists():
            print(f" Storage folder not found: {storage_dir.resolve()}")
            print("Please create a 'storage' folder and put your binary file in it.")
            return
        
        # Get the first file in storage folder
        files = [f for f in storage_dir.iterdir() if f.is_file()]
        
        if not files:
            print(f" No files found in storage folder: {storage_dir.resolve()}")
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
            print(f" Binary file '{binary_path}' not found in current directory.")
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
        
        print(f"\n Analysis complete! Project saved as '{project_name}'")
        if project_dir:
            print(f"Project location: {Path(project_dir).resolve()}")
        
    except FileNotFoundError as e:
        print(f"Setup Error: {e}")
    except subprocess.CalledProcessError as e:
        print(f"Execution Error: {e}")
    except Exception as e:
        print(f"Unexpected Error: {e}")

if __name__ == "__main__":
    main()
    # export_with_pyghidra()
    export_consolidated_code_and_data()



