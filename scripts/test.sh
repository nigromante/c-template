#!/usr/bin/env bash
echo "-----------------------------------------------------"
REAL_DIR=$(realpath $1)
shift
echo "LD_LIBRARY_PATH = ${REAL_DIR}"
export LD_LIBRARY_PATH="${REAL_DIR}"

echo "-----------------------------------------------------"
echo "RUN :: $@"

time {
    echo "-----------------------------------------------------"
    eval "$@"
    echo "-----------------------------------------------------"
}   
echo
