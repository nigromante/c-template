#!/usr/bin/env bash
cwd=$(dirname $(realpath "$0"))
export LD_LIBRARY_PATH="${cwd}/libs"
valgrind --leak-check=full --log-file=analisis -s $@ 
