import os

if os.fork():
	os.execv('/bin/echo', ['echo','hello '])

print("hhh")