#!/usr/bin/env bash

function x {
    echo "$0"
    return
}


function y {
    read -p "enter num> "
    if [[ "$REPLY" =~ ^-?[0-9]+$ ]]; then
        echo 'param is number'
        if (( $REPLY > 100 )); then
            return
        fi
        if (( (("$REPLY" % 2)) == 0 )); then
            echo 'num is even and less than 100'
        else
            echo 'num is odd'
        fi
    else
        echo 'param is not a number'
        return
    fi
}

