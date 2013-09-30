#! /bin/bash

h=$1
ex=$2
path=$3

if [ "$h" == "h1" ]; then
	time ./exe/a_star_h1 < $2 > $3
elif [ "$h" == "h2" ]; then
	time ./exe/a_star_h2 < $2 > $3
elif [ "$h" == "h3" ]; then
	time ./exe/a_star_h3 < $2 > $3
elif [ "$h" == "h4" ]; then
	time ./exe/a_star_h4 < $2 > $3
fi
