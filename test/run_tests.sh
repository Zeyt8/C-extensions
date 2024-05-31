#!/bin/bash

if [ "$1" != "string" ] && [ "$1" != "list" ]; then
    echo "Usage: $0 {string|list}"
    exit 1
fi

cd "$1"

make all
make run
make clean

cd ..