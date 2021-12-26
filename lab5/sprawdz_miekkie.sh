#!/bin/bash

if (( $# != 1))
then
    echo "Błędne parametry"
    exit
fi

output=$(find $1 -type l ! -readable)
num=$(echo $output | wc -w)

echo  "$num petli w katalogu $1"

while read p; do 
    echo "$p ----> dlugosc petli $(ls -la $p | grep -c '\->')"
done < output
