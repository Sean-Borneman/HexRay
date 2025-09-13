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
