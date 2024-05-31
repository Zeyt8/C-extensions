#!/bin/bash

build() {
    make all
}

run() {
    for test in *_tests; do
        if ! ./$test; then
            echo "$test failed."
            exit 1
        fi
    done
}

clean() {
    make clean
}

if [ "$1" != "string" ] && [ "$1" != "list" ]; then
    echo "Usage: $0 {string|list} {build|run|clean|all}"
    exit 1
fi

cd "test/$1"

case $2 in
    build)
        build
        ;;
    run)
        run
        ;;
    clean)
        clean
        ;;
    all)
        build
        run
        clean
        ;;
    *)
        echo "Invalid command. Usage: $0 {string|list} {build|run|clean|all}"
        exit 1
        ;;
esac

cd ..