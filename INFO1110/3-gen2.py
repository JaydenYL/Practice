#Similar to the previous question, generate a number sequence which will oscillate between -0.5 and 0.5.

import math
import sys

a = int(input('Give me a number: '))
#a = int(sys.argv[1])

i = 0

while i < a-1:
	while i % 3 == 0:
		print(-0.5,end =', ')
		i += 1
	while i % 3 == 1:
		print(0, end = ', ')
		i += 1
	while i % 3 == 2:
		print(0.5, end = ', ')
		i += 1
while i % 3 == 0:
	print(-0.5)
	break 
while i % 3 == 1:
	print(0)
	break
while i % 3 == 2:
	print(0.5)
	break
	