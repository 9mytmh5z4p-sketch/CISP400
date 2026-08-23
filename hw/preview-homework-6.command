#!/bin/zsh
set -u
unsetopt BG_NICE 2>/dev/null || true
script_dir="${0:A:h}"
project_dir="${script_dir:h}"
cd "$project_dir" || exit 1
python_command="$(command -v python3)"
if [[ -z "$python_command" ]]; then echo "Python 3 is required."; read -r; exit 1; fi
port=8765
while /usr/bin/nc -z 127.0.0.1 "$port" >/dev/null 2>&1; do (( port += 1 )); done
"$python_command" -m http.server "$port" --bind 127.0.0.1 >/private/tmp/p400-homework-preview.log 2>&1 &
server_pid=$!
cleanup() { kill "$server_pid" >/dev/null 2>&1 || true; }
trap cleanup EXIT INT TERM
for _ in {1..30}; do if /usr/bin/nc -z 127.0.0.1 "$port" >/dev/null 2>&1; then break; fi; sleep 0.1; done
preview_url="http://127.0.0.1:${port}/hw/Programming%20Homework%206.html"
open "$preview_url"
echo "Homework 6 preview is running at: $preview_url"
wait "$server_pid"
