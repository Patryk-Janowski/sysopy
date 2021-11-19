#!/bin/bash

if (( $# == 0))
then
    echo "Brak parametrów."
    exit
fi

tab=( "$@" )
echo "${tab[@]}" | rev