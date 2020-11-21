#!/usr/bin/env python3

import os,sys

STDIN = 0 
STDOUT = 1 

pipein, pipeout = os.pipe()
if os.fork():
	# parent
	os.close(pipeout)
	os.dup2(pipein, STDIN)
	ss = sys.stdin
	print(ss.readlines())
	# not reached
	os._exit(127)
else:
	# child
	os.close(pipein)
	os.dup2(pipeout, STDOUT)
	os.execvp('ps', 'ps'.split())
	# not reached
	os._exit(127)