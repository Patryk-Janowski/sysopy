#!/bin/bash

if (( $# != 1)); then
    echo "Błędne parametry"
    exit 1
elif [[ ! -d $1 ]]; then
    echo "$1 nie jest katalogiem"
    exit 1
fi

find $1 -type l ! -readable > output.txt
num=$(echo $output | wc -w)

echo  "$num petli w katalogu $1"

while read p; do 
    echo "$p ----> dlugosc petli $(ls -la $p | grep -c '\->')"
done < output.txt
rm output.txt
