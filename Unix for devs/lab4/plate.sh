#!/bin/bash

code=`echo $1 | cut -c 1-3`
chars=`echo $1 | cut -c 4-6`
numbers=$2
allowedNumbers='^[0-9_]'
allowedChars='^[A-Z_]'
declare -a arr=( "B" "F" "G" "I" "O" "Q" )

if  ! [[ $numbers =~ $allowedNumbers ]]; then
		echo "wrong number input"
		exit
fi

if ! [[  $chars =~ $allowedChars ]]; then
		echo "wrong char input"
		exit
fi


if [ "${1:5:1}" != "" ]; then
    echo ${1:5:1}
	echo "bad seperator"
	exit -1
fi

if [ ${numbers:0:1} == 0 ]; then
	echo "number part has to start with 1__"
	exit
fi
printflag=false
declare -a oldplates
oldplates+=("placeholder")
if [ "$code" = "DA-" ] || [ "$code" = "DI-" ]; then
	echo "richtige Eingaben"
 for i in "${arr[@]}"
    do
        for j in {0..9}
        do
            part1=`echo $chars | sed s:_:$i:`
            part2=`echo $numbers | sed s:_:$j:`
            newplate=`echo $code$part1-$part2`
			for k in ${oldplates[@]}; do
				#echo $k
				 if [ "$newplate" == $k ]; then
				 	printflag=false
					break	
				 else
					printflag=true
				 fi
				done
			if [ "$printflag" == true ]; then
				oldplates+=($newplate)
				echo $newplate
			fi
        done
    done
else
	echo "Falsche eingaben"
fi