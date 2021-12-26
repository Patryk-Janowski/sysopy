#!/bin/bash

if (( $# != 1)); then
    echo "Błędne parametry"
    exit 1
elif [[ ! -d $1 ]]; then
    echo "$1 nie jest katalogiem"
    exit 1
fi

echo "Inode   | Links | File name";
echo "----------------------------------";
ls -il $1 | tail -n +2 | sort | awk -F' ' '$3 > 1 {print $1"\t|"$3"\t| "$NF}';
