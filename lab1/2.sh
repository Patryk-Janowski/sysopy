#!/bin/bash

echo -e "guess.bash - Guess a number between $1 and $2\n"

(( answer = RANDOM % $2 + $1 ))
num=0

while (( guess != answer )); do
	num=$(($num+1))
	read -p "Enter guess $num: " guess
	if (( guess < answer )); then
		echo "Higher..."
	elif (( guess > answer )); then
		echo "Lower..."
	fi
done
echo -e "Correct! That took $num guesses.\n"