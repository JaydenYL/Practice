import os

if os.fork():
	os.execv('/bin/echo', ['/bin/echo' ,'hello world'])

print("hhh")