#!/bin/bash

aim=$1
while IFS=",", read  name number trash
do
#	echo "$name: $number"
	if [ "$name" == "$aim" ]; 
		then echo "Name: $name, Phone Number: $number"; 
	fi
done 