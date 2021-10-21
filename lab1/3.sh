#!/bin/bash

# echo $(($1**$2))

res=$1

for number in {0..$2}
do
res=$(($res * $1))
done

echo $res