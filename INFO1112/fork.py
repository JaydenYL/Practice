import os
import time

print ("Before fork process pid=%s, ppid=%s" % (os.getpid(), os.getppid()))

pid = os.fork() #会有两个进程运行这之后的代码，它们的pid（process id）不一样

if pid == 0:
	print ("I am child process pid=%s, ppid=%s" % (os.getpid(), os.getppid()))
#	time.sleep(5)
else:
	print ("I am parent process pid=%s, ppid=%s" % (os.getpid(), os.getppid()))
#	time.sleep(5)

# 下面的内容会被打印两次，一次是在父进程中，一次是在子进程中。
print ("After fork process pid=%s, ppid=%s" % (os.getpid(), os.getppid()))