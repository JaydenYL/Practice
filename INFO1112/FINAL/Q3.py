#!/usr/bin/env python3

import sys, re, os

if (len(sys.argv) < 3):
	quit()

folder, aim = sys.argv[1], sys.argv[2]
file_size = {}

regex = re.compile('({})'.format(reg))

for root, dirs, files in os.walk(directory):
	for f in files:
		if regex.match(f):
				file_size[f] == os.path.getsize(f)
			
max_key = max(file_size.get())
print(max_key + " : " + file_size[max_key])