#!/bin/zsh
set -u
script_dir="${0:A:h}"; project_dir="${script_dir:h}"; cd "$project_dir" || exit 1
python_command="$(command -v python3)"; if [[ -z "$python_command" ]]; then exit 1; fi
port=8765; while /usr/bin/nc -z 127.0.0.1 "$port" >/dev/null 2>&1; do (( port += 1 )); done
"$python_command" -m http.server "$port" --bind 127.0.0.1 >/private/tmp/p400-homework-preview.log 2>&1 & server_pid=$!
cleanup() { kill "$server_pid" >/dev/null 2>&1 || true; }; trap cleanup EXIT INT TERM
preview_url="http://127.0.0.1:${port}/hw/Programming%20Homework%205.html"; open "$preview_url"; wait "$server_pid"
