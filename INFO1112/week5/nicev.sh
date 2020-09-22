#!/bin/bash

aim=$1
new_nice=$2
ps |
while IFS=",", read  ppid tty tm cmd
do
	if [ "$cmd" == "${aim}*" ]; 
		then echo "Found"
	fi
done 