#!/usr/bin/env bash

if (( $# == 0))
then
    echo "Brak parametrów."
    exit
fi

arr=( "$@" )
echo "${arr[@]}" | rev