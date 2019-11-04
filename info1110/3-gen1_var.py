#As an extension, create a variation that will increment the starting value after 4 numbers have been printed out.

import sys

a = int(input('Give me a number: '))
#a = int(sys.argv[1])

i = 0
n = 0
while i < a-1 :
	print((i%4)+int(i/4),end = ', ')
	i += 1	
print((a-1)%4 + int(a/4))

	