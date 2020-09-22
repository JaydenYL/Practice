#!/bin/bash

aim=$1
declare -i new_nice
new_nice=$2
ps >> tmp
while IFS=" ", read  ppid tty tm cmd
do
	if [ "$cmd" == "${aim}*" ]; 
		then renice $new_nice -p $ppid
	fi
done < tmp
rm tmp