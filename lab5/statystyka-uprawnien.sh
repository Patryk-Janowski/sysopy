#!/bin/bash

if (( $# != 1)); then
    echo "Błędne parametry"
    exit 1
elif [[ ! -d $1 ]]; then
    echo "$1 nie jest katalogiem"
    exit 1
fi

find $1 -exec stat {} --format="%A" \; | sort | uniq -c | awk '{print $2,$1}'


# stat ex_1_7.sh --format="%A" 