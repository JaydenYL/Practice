##!/usr/bin/env python3
#
#import sys, re, os
#
#if (len(sys.argv) < 3):
#	quit()
#
#folder, aim = sys.argv[1], sys.argv[2]
#file_size = {}
#
#regex = re.compile('({})'.format(aim))
#
#for root, dirs, files in os.walk(folder):
#	for f in files:
#		if regex.match(f):
#			file_size[f] == os.path.getsize(f)
#			
#max_key = max(file_size, key=file_size.get)
#print("{} : {}".format(max_key,  file_size[max_key]))

import sys
import os
import re

directory = sys.argv[1]
reg = sys.argv[2]
dirandsize = {}

regex = re.compile('({})'.format(reg))

for root, dirs, files in os.walk(directory):
	for f in files:
		if regex.match(f):
				dirandsize[f] = os.path.getsize(f)
			
max_key = max(dirandsize, key=dirandsize.get)
print(max_key + " : " + dirandsize[max_key])