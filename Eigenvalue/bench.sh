#!/biin/bash

set -e

CFILE="fin.c"
OUTPUT="out"
LOG_FILE="bench.txt"

echo "Compiling..."
gcc -O3 -g -lm "$CFILE" -o "$OUTPUT"

for I in $(seq 3 100); do
    echo -n "$I " >> "$LOG_FILE"
    { /usr/bin/time -f "%e" ./"$OUTPUT" "$I"; } 2>> "$LOG_FILE"
done
