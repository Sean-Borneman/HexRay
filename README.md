# Hack-CMU-2025
To set up package dependencies

git clone https://github.com/Denloob/ghidra-cli
cd ghidra-cli

# Set the environment variable
export ANTHROPIC_API_KEY="your-new-api-key-here"
export ANTHROPIC_API_KEY="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"

# Run the program without exposing the key
python backend/backendscript.py /path/to/binary
