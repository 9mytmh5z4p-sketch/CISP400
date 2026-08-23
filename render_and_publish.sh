#!/usr/bin/env bash

set -e

# ---- 1. Require a commit message ----
if [ $# -eq 0 ]; then
  echo "ERROR: You must supply a commit message."
  echo "Usage: $0 \"Your commit message here\""
  exit 1
fi

COMMIT_MESSAGE="$1"

# ---- 2. Ensure we are in the repo root ----
REPO_ROOT="$(git rev-parse --show-toplevel)"
cd "$REPO_ROOT"

echo "Repo root: $REPO_ROOT"
echo "Rendering Quarto files..."

# ---- 3. Render each index.qmd file directly (NO project assumption) ----
find . -type f -name "index.qmd" | while read -r qmd; do
  echo "  Rendering $qmd"
  quarto render "$qmd"
done

# ---- 4. Check for actual changes ----
if git diff --quiet; then
  echo "No content changes detected. Nothing to commit."
  exit 0
fi

# ---- 5. Stage, commit, push ----
git add .
git commit -m "$COMMIT_MESSAGE"
git push

echo "Done."