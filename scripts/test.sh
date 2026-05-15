#!/usr/bin/env bash
echo "-----------------------------------------------------"
echo $@

REAL_DIR=$1

echo "LD_LIBRARY_PATH = ${REAL_DIR}" 
shift

export LD_LIBRARY_PATH=${REAL_DIR}

time {
    echo "-----------------------------------------------------"
    $@
    echo "-----------------------------------------------------"
}   
echo
