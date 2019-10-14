#!/bin/bash

initAge=18
maxAge=70
currentTime=`date -d "2018-01-17" +%s `
donationNo=0 #we count from 0 because thats how its done :)
secondsaday=86400
secondstwomonth=5256000 #seconds a day * (365/6) because she can do 6 donations a year and it have even dates
currentTimePrint=`date -d "@$currentTime" +%d.%m.%Y`
printf "%-20s %-50s %-20s\n\n" "Donation No." "Date of Donation" "Age"
	
while [ $initAge -ne $maxAge ]; do
		printf "%-20s %-50s %-20s \n" $donationNo "$currentTimePrint" $initAge
		donationNo=`expr $donationNo + 1`
		currentTime=`expr $currentTime + $secondstwomonth`
		currentTimePrint=`date -d "@$currentTime" +%d.%m.%Y`
		if [ `expr $donationNo % 6` = 0 ]; then
			initAge=`expr $initAge + 1`
		fi
done

