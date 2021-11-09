#!/bin/bash


if (( $# != 2 )); then
	echo 'Invalid num of params'
	exit 1
fi


if [[ $1 =~ ^[0-9]+$ && $2 =~ ^[0-9]+$ ]]; then

	echo -e "guess.bash - Guess a number between $1 and $2"

	(( answer = RANDOM % $2 + $1 ))
	num=0

	while (( guess != answer )); do
		num=$(($num+1))
		read -p "enter guess $num: " guess
		if (( guess < answer )); then
			echo "too low"
		elif (( guess > answer )); then
			echo "to high"
		fi
	done
		echo -e "correct quess in $num guesses"
else
	echo 'wrong data'
	exit 1
fi