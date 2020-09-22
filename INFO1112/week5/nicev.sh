#!/bin/bash

csvfile=$1
aim=$2
while IFS=",", read  name number trash
do
	if [ "$name" == "$aim" ]; 
		then echo "Name: $name, Phone Number: $number"; 
	fi
done 