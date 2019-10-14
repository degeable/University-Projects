#!/bin/sh


if [ "$#" -ne 2 ]; then
future_year=50
start_month=1
start_year=2019
else
#EXTENDED 
future_year=$2
start_month=`echo $1 | cut -c 1-2` 
start_year=`echo $1 | cut -c 3-6`
#EXTENDED 
fi
goal_year=`expr $start_year + $future_year`

echo "start month:" $start_month
echo "start year:" $start_year
echo "start month:" $future_year
echo "goal year:" $goal_year
printf "\n\n%5s %s\n ---------\n" "year" "month"
while [ "$start_year" -lt "$goal_year" ]; do
	 start_year=`expr $start_year + 1`
	 #echo "current year:" $start_year
		while [ "$start_month" -lt 12 ]; do
			#echo "current month:" $start_month			
				if [ `ncal $start_month $start_year | grep "13" | grep "Fr" | wc -l` -gt 0 ]; then	
					month=`ncal $start_month $start_year | head -n 1 | cut -d " " -f 5` 
					year=`ncal $start_month $start_year | head -n 1 | cut -d " " -f 6`
					printf "%5s %s\n"  $year $month
				fi
			start_month=`expr $start_month + 1`
			done
		start_month=1
done
