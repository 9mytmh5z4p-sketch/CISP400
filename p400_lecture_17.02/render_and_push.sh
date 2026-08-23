#!/bin/bash

# Change to the directory where this script is located
cd "$(dirname "$0")"

# Source conda directly from miniforge3
source ~/miniforge3/etc/profile.d/conda.sh

# Activate the quarto environment
conda activate quarto

echo "Working in directory: $(pwd)"

# Render the lecture file that matches this folder name
QMD_FILE="$(basename "$(pwd)").qmd"

if [ ! -f "$QMD_FILE" ]; then
    echo "Error: Expected $QMD_FILE in this directory!"
    read -p "Press Enter to close..."
    exit 1
fi

# Render the Quarto presentation
echo "Rendering Quarto presentation: $QMD_FILE"
quarto render "$QMD_FILE"

# Check if render was successful
if [ $? -ne 0 ]; then
    echo "Error: Quarto render failed!"
    read -p "Press Enter to close..."
    exit 1
fi

echo "Render successful!"

# Add all changes
echo "Adding changes to git..."
git add .

# Commit with message
echo "Committing changes..."
git commit -m "Updated content"

# Push to GitHub
echo "Pushing to GitHub..."
git push

# Check if push was successful
if [ $? -eq 0 ]; then
    echo "Successfully pushed to GitHub!"
else
    echo "Error: Git push failed!"
fi

# Keep terminal open so you can see the results
read -p "Press Enter to close..."
