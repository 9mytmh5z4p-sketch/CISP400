#!/bin/zsh

set -u
unsetopt BG_NICE 2>/dev/null || true

script_dir="${0:A:h}"
cd "$script_dir" || exit 1

python_command="$(command -v python3)"
if [[ -z "$python_command" ]]; then
  echo "Python 3 is required to preview the syllabus."
  echo "Press Return to close this window."
  read -r
  exit 1
fi

port=8765
while /usr/bin/nc -z 127.0.0.1 "$port" >/dev/null 2>&1; do
  (( port += 1 ))
done

"$python_command" -m http.server "$port" --bind 127.0.0.1 >/private/tmp/p400-syllabus-preview.log 2>&1 &
server_pid=$!

cleanup() {
  kill "$server_pid" >/dev/null 2>&1 || true
}
trap cleanup EXIT INT TERM

server_ready=false
for _ in {1..30}; do
  if /usr/bin/nc -z 127.0.0.1 "$port" >/dev/null 2>&1; then
    server_ready=true
    break
  fi
  sleep 0.1
done

if [[ "$server_ready" != true ]]; then
  echo "The syllabus preview could not be started."
  echo "Press Return to close this window."
  read -r
  exit 1
fi

open "http://127.0.0.1:${port}/p400-syllabus%28LIVE%29.html"

echo "Syllabus preview is running at:"
echo "http://127.0.0.1:${port}/p400-syllabus%28LIVE%29.html"
echo
echo "Edit p400-syllabus(LIVE).md, save it, then reload the browser page."
echo "Press Control-C or close this window to stop the preview."

wait "$server_pid"
