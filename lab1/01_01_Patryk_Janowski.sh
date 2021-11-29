#!/usr/bin/env bash


if (( $# != 2 )); then
    echo 'Invalid num of params'
    exit 1
fi


DIR=$1
SIZE=$2

if [[ -d $DIR && $SIZE =~ ^[0-9]+$ ]]; then
    result=$(find $DIR -size +${SIZE} -type f -exec stat -f '%a:%N' "{}" \; | sort -nr | cut -d':' -f2 | head -1)
    ls -la $result
else
    echo 'Wrong params'
fi

