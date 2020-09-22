#!/bin/bash

while IFS=, read -r field1 field2
do
	echo "$field and $field2"
done < input.csv