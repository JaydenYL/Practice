#!/bin/bash

for each_file in `find $1 -type f -name $2 | awk '.' '{print $2"."$3}' `
do 
	echo `pwd`|$each_file
done