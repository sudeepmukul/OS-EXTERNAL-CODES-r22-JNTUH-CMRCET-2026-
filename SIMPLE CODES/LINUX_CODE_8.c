#!/bin/bash

for item in "$@"
do
    if [ -f "$item" ]
    then
        echo "$item is a File"
        lines=$(wc -l < "$item")
        echo "Number of lines: $lines"

    elif [ -d "$item" ]
    then
        echo "$item is a Directory"

    else
        echo "$item does not exist"
    fi
done