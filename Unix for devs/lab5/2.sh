#!/bin/sh

if [ "$#" -ne 4 ]; then
	echo "Usage $0 INPUTFILE COUNTRYCODE START END"
	exit 0
fi
# pass the arguments to awk with -v flag
awk -v  code=$2 -v start=$3 -v end=$4  -F	',' '{if(($2 == code) && ($3>=start) && ($3<=end)){print $3 " "$4;}}' $1 > filtered.data

gnuplot pop.conf 