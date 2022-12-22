#!/bin/sh

make clean
for filename in tests/case_*.pcat; do
    make INPUT="$filename"
done