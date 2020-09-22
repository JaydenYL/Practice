#!/bin/bash

aim=$1
while IFS=, read  name number trash
do
	if ["$name"=="$aim"]; then echo "Name: $name, Phone Number: $number"; if
done 