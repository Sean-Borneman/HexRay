import subprocess
import os

def find_first_c_file(folder_path):
    """Return the first .c file found in folder_path, or None if none exists."""
    if not os.path.exists(folder_path):
        return None
    for file in os.listdir(folder_path):
        if file.endswith(".c"):
            return file
    return None

def check_c_syntax(c_file_path):
    """Return True if C file compiles (syntax only), False otherwise."""
    # Path to local GCC
    script_dir = os.path.dirname(__file__)
    compiler_path = os.path.join(script_dir, "mingw64", "bin", "gcc.exe")

    # Run GCC with syntax-only, warnings off, and define true/false
    result = subprocess.run(
        [
            compiler_path,
            "-std=gnu89",
            "-fsyntax-only",
            "-w",
            "-Dtrue=1",
            "-Dfalse=0",
            c_file_path
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    if result.returncode == 0:
        return True
    else:
        print(result.stderr)
        return False

if __name__ == "__main__":
    # Absolute path to results folder
    project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
    results_folder = os.path.join(project_root, "storage/results")

    c_file = find_first_c_file(results_folder)

    if not c_file:
        print("No .c files found in results folder:", results_folder)
    else:
        c_file_path = os.path.join(results_folder, c_file)
        if check_c_syntax(c_file_path):
            print(f"{c_file} is syntactically valid.")
        else:
            print(f"{c_file} has syntax errors.")
