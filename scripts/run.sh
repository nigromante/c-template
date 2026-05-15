#!/usr/bin/env bash

REAL_DIR=$(dirname "$(readlink -f "$0")")
source ${REAL_DIR}/exports.sh

./$@
