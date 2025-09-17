# HeXray (Hack-CMU-2025)
HeXray is a decomiplation tool for binary and .exe files that severs an an evolution to ghidra. Instead of using purely deterministic decompilation method, HeXray attempts to de-obfuscate the code and make it as readable as possible to the user. 
#UI
HeXray takes in your file then either analyses it outputing the deobfuscated c code source file along with a full explanation of the code and its vulnerabilities or (such as in the case of a CTF challenge) attempts to fully exploit the script and grab the flag, defuse the bomb, what have you. 
## The HeXray UI
### UI upon accepting a file

<img width="2559" height="1336" alt="image" src="https://github.com/user-attachments/assets/931d4374-60ab-43b4-8ae2-3a920e5438c6" />

### UI after basic analysis (on the windows calculator)

<img width="2558" height="1333" alt="image" src="https://github.com/user-attachments/assets/8c643e1e-6367-4669-80f2-0af594705d9b" />

### UI after a full auto hack exploit exploration

<img width="2559" height="1346" alt="image" src="https://github.com/user-attachments/assets/00aeddfe-628e-4909-b058-5171e89ecbdb" />

# How it works

HeXray first leverage the ghidra cli to decompile the given file. we then concatonate the C functions and pass it to the anthropic API which de-obfuscates the code (adding typing, changing variable names). After that we use GCC to build the C-code and make sure the AI hasn't hallucenated any functions, this is how we ensuredeterministic behavoir on a probablistic compiler. 

# Instalation instructions (set up package dependencies)
# install ghidra
needs JDK 22+ installed first
ghidra version 11.14.2
in main repo: mkdir Ghidra_open_source_install
put in "Ghidra_open_source_install" folder in main repo
set up environment variable:

$env:GHIDRA_INSTALL_DIR = "C:\Users\James\Documents\Hack-CMU-2025\Ghidra_full_open_source_install\ghidra_11.4.2_PUBLIC"


# open up virtual environment
python -m venv venv
./venv/Scripts/activate

# Download dependencies
git clone https://github.com/Denloob/ghidra-cli
pip -m pip  install anthropic
python -m pip install pyghidra

# install npm
Install npm from your favorite source
https://nodejs.org/en/download

# Basic usage (analyzes everything)
python .\backend\main.py 

# With environment variable for API key
export ANTHROPIC_API_KEY="your-api-key"
python main_pipeline.py binary.exe

# Only analyze code sections
python main_pipeline.py binary.exe --no-data

# Custom analysis prompt
python main_pipeline.py binary --prompt "Focus on encryption and security"

# Skip summary generation
python main_pipeline.py binary --no-summary

# Enable chunking (off by default)
python backend/llm_analyzer.py storage/challoutput.c --type code --chunk
python backend/llm_analyzer.py storage/challdump.txt --type data --chunk

# Ghidra export (code + data) first
python backend/main_pipeline.py /path/to/binary --use-ghidra-with-data

## Configuration

You can provide your Anthropic API key via any of these (checked in order):

1) CLI flag: `--api-key YOUR_KEY`
2) Environment variable: `ANTHROPIC_API_KEY`
3) Project config file: `backend/config.json`
4) User config file: `~/.config/ghidra-llm/config.json`

Project-local config setup:

- Copy `backend/config.example.json` to `backend/config.json`
- Put your key in the `anthropic_api_key` field

Example `backend/config.json`:

{
  "anthropic_api_key": "sk-ant-..."
}

Note: `backend/config.json` is ignored by git to avoid committing secrets.
