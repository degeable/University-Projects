#!/bin/bash


allowedNumbers='^[0-9_]'
allowedChars='^[A-Z_]'

code=`echo $1 | cut -c 1-3`
char[0]=`echo $1 | cut -c 4-4`
char[1]=`echo $1 | cut -c 5-5`
number[0]=`echo $2 | cut -c 1-1`
number[1]=`echo $2 | cut -c 2-2`
number[2]=`echo $2 | cut -c 3-3`

for i in ${number[@]}
	do
	echo $i
	if  ! [[ $i =~ $allowedNumbers ]]; then
		echo "wrong number input"
		exit
	fi
done

for i in ${char[@]}
	do
		echo $i

	if ! [[  $i =~ $allowedChars ]]; then
		echo "wrong char input"
		exit
	fi
done

if [ "${1:5:1}" != "" ]; then
    echo ${1:5:1}
	echo "invalid seperator format"
	exit -1
fi

if [ ${number[0]} == 0 ]; then
	echo "number part has to start with 1__"
	exit
fi

declare -a arr=( "B" "F" "G" "I" "O" "Q" )
oldplate=""
if [ "$code" = "DA-" ] || [ "$code" = "DI-" ]; then
	echo "richtige Eingaben"
    for i in "${arr[@]}"
		do
		    for j in "${arr[@]}"
				do
					for k in {1..9}
						do
							for l in {0..9}
								do
									for m in {0..9}
										do
											if [ "${char[0]}" == "_" ]; then 

												newChar1=`echo ${char[0]} | sed s:_:$i:`
											else
												newChar1=`echo ${char[0]}`
											fi
											if [ "${char[1]}" == "_" ]; then 
												newChar2=`echo ${char[1]} | sed s:_:$j:`
											else
												newChar2=`echo ${char[1]}`
											fi
											if [ "${number[0]}" == "_" ]; then 
												newNumber1=`echo ${number[0]} | sed s:_:$k:`
											else
												newNumber1=`echo ${number[0]}`
											fi
											if [ "${number[1]}" == "_" ]; then 
												newNumber2=`echo ${number[1]} | sed s:_:$l:`
											else
												newNumber2=`echo ${number[1]}`	
											fi
											if [ "${number[2]}" == "_" ]; then 
												newNumber3=`echo ${number[2]} | sed s:_:$m:`
											else
												newNumber3=`echo ${number[2]}`	
											fi
													newplate=`echo $code$newChar1$newChar2 $newNumber1$newNumber2$newNumber3`
											    if [ "$oldplate" != "$newplate" ]; then
													oldplate=$newplate
													echo $oldplate
												fi
										
									done
							done
					done
			done
	done
else
	echo "Falsche eingaben"
fi