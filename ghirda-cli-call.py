import subprocess
import os
from pathlib import Path

class WindowsGhidraCLI:
    def __init__(self):
        self.script_path = Path("./ghidra-cli").resolve()
        self.executor = self._find_bash_executor()
    
    def _find_bash_executor(self):
        """Find a way to execute bash scripts on Windows"""
        executors = [
            # Git Bash
            (r"C:\Program Files\Git\bin\bash.exe", "git_bash"),
            (r"C:\Program Files (x86)\Git\bin\bash.exe", "git_bash"),
            # WSL
            ("wsl", "wsl"),
            # System bash
            ("bash", "bash"),
        ]
        
        for exe_path, exe_type in executors:
            try:
                if exe_type == "wsl":
                    subprocess.run([exe_path, "--help"], 
                                 capture_output=True, check=True, timeout=5)
                else:
                    if Path(exe_path).exists() or exe_type == "bash":
                        subprocess.run([exe_path, "--version"], 
                                     capture_output=True, check=True, timeout=5)
                
                print(f"✓ Found executor: {exe_type}")
                return (exe_path, exe_type)
            except:
                continue
        
        raise RuntimeError("No bash executor found. Please install Git for Windows or WSL.")
    
    def _convert_to_bash_path(self, windows_path):
        """Convert Windows path to Git Bash compatible path"""
        path = Path(windows_path).resolve()
        path_str = str(path)
        
        # Convert C:\Users\... to /c/Users/...
        if path_str[1:3] == ':\\':
            drive_letter = path_str[0].lower()
            rest_of_path = path_str[3:].replace('\\', '/')
            return f"/{drive_letter}/{rest_of_path}"
        
        return path_str.replace('\\', '/')
    
    def run(self, args, cwd=None):
        """Execute ghidra-cli with arguments"""
        exe_path, exe_type = self.executor
        
        if exe_type == "git_bash":
            # Convert script path to Git Bash format
            bash_script_path = self._convert_to_bash_path(self.script_path)
            cmd = [exe_path, bash_script_path] + args
            
            # Convert working directory if provided
            if cwd:
                bash_cwd = self._convert_to_bash_path(cwd)
                # Use cd command in bash
                bash_command = f'cd "{bash_cwd}" && bash "{bash_script_path}" {" ".join(args)}'
                cmd = [exe_path, "-c", bash_command]
            
        elif exe_type == "wsl":
            cmd = [exe_path, "bash", str(self.script_path)] + args
        else:
            cmd = [exe_path, str(self.script_path)] + args
        
        try:
            print(f"Running: {' '.join(cmd[:3])}...")  # Don't print full path for readability
            result = subprocess.run(
                cmd,
                cwd=None if exe_type == "git_bash" and cwd else cwd,  # Let bash handle cwd
                capture_output=True,
                text=True,
                check=True
            )
            return result
        except subprocess.CalledProcessError as e:
            print(f"❌ Command failed")
            print(f"Error: {e.stderr}")
            print(f"Output: {e.stdout}")
            raise

# Alternative simpler approach - just use bash -c with a command string
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
            print(f"❌ Command failed: {bash_command}")
            print(f"Error: {e.stderr}")
            print(f"Output: {e.stdout}")
            raise

# Usage
def main():
    try:
        # Use the simpler approach
        ghidra = SimpleGhidraCLI()
        
        # Test with help
        print("Testing ghidra-cli...")
        result = ghidra.run(["-n -i ./engine"])
        print("✓ ghidra-cli is working!")
        print("Help output:")
        print(result.stdout)
        
        # Test analyzing a binary (uncomment when you have a binary to test)
        # result = ghidra.run(['-n', '-i', './my_binary.exe', '--name', 'test'])
        # print("✓ Analysis completed!")
        
    except FileNotFoundError as e:
        print(f"❌ Setup Error: {e}")
    except subprocess.CalledProcessError as e:
        print(f"❌ Execution Error: {e}")
        if "No such file or directory" in str(e.stderr):
            print("\nMake sure the ghidra-cli script is in your current directory.")
            print(f"Looking for: {Path('./ghidra-cli').resolve()}")
            print(f"File exists: {Path('./ghidra-cli').exists()}")
    except Exception as e:
        print(f"❌ Unexpected Error: {e}")

if __name__ == "__main__":
    main()