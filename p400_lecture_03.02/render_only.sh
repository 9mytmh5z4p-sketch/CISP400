#!/bin/bash

# Change to the directory where this script is located
cd "$(dirname "$0")"

# Source conda directly from miniforge3
source ~/miniforge3/etc/profile.d/conda.sh

# Activate the quarto environment
conda activate quarto

echo "Working in directory: $(pwd)"

# Find the .qmd file in the current directory
QMD_FILE=$(ls p400_lecture_*.qmd 2>/dev/null | head -n 1)

if [ -z "$QMD_FILE" ]; then
    echo "Error: No .qmd file found in this directory!"
    read -p "Press Enter to close..."
    exit 1
fi

# Render as RevealJS with no-execute flag
echo "Rendering Quarto presentation: $QMD_FILE"
quarto render "$QMD_FILE" --no-execute

# Check if render was successful
if [ $? -ne 0 ]; then
    echo "Error: Quarto render failed!"
    read -p "Press Enter to close..."
    exit 1
fi

echo "Render successful!"
open "${QMD_FILE%.qmd}.html"  # Auto-open the slides
