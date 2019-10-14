#!/bin/bash

initAge=18
startAge=18
maxAge=70
currentTime=`date -d "2018-01-17" +%s `
donationNo=0 #we count from 0 because thats how its done :)
secondsaday=86400
secondstwomonth=5256000 #seconds a day * (365/6) because she can do 6 donations a year and it have even dates
currentTimePrint=`date -d "@$currentTime" +%d.%m.%Y`
initialMoney=0
moneyPaid=5

header=`printf "%-15s %-16s %-15s %-15s %-15s \n\n" "Donation No." "Date of Donation" "Age" "Money paid" "Total Money"`	

while [ $initAge -ne $maxAge ]; do
		text=`printf "%-15s %-16s %-15s %-15s %-15s \n" $donationNo "$currentTimePrint" $initAge $moneyPaid $initialMoney` #the text displayed
		initialMoney=`expr $initialMoney + $moneyPaid` 
		donationNo=`expr $donationNo + 1`
		currentTime=`expr $currentTime + $secondstwomonth`  #time in seconds
		currentTimePrint=`date -d "@$currentTime" +%d.%m.%Y` # convert to readable date
		if [ `expr $donationNo % 6` = 0 ]; then # after 6 donations a year passed so the age goes up
			initAge=`expr $initAge + 1`
		fi
		percent=`echo "scale=2; (($initAge - $startAge )/52)*100" | bc | cut -d "." -f 1` #just want to have a "rounded" number. I thought this is sufficient
		
		#from manpage:  --gauge        <text> <height> <width> [<percent>]
		echo $percent | dialog --title "Blood Donation" --sleep 1 --gauge "$header\n$text" 20 80 $percent
		#note: without the echo the dialog would just freeze and continue to the next with a strg+c... dont know why
done
 