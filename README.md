# Hack-CMU-2025
To set up package dependencies

git clone https://github.com/Denloob/ghidra-cli

# Basic usage (analyzes everything)
python main_pipeline.py /path/to/binary

# With environment variable for API key
export ANTHROPIC_API_KEY="your-api-key"
export ANTHROPIC_API_KEY="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"
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
