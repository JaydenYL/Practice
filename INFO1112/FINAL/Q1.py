# answer to Q1

import sys ,time, os

pid = os.fork() 
try:
	if pid != 0:
		print ("waiting for PID", pid) 
		child_pid, exit_code = os.wait()
		print ("process ID was {}".format(child_pid)) 
	elif pid == 0:
		time.sleep(5)
		print ("exit with status 99.") 
		os.exit(99) 
except OSError:
	print ("yikes! fork failed!") 
	sys.exit(1) 
	
	