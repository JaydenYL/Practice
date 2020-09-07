#Without using any lists or if statements (just a loop), write a program that generates a number sequence with n iterations. This program will have to output each individual number from the sequence inside the loop.
#The program must generate the sequence: 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3... Hint: Use the modulo operator and a while loop to solve this problem.

import sys

a = int(input('Give me a number: '))
# a = int(sys.argv[1])

i = 0
while i < a-1 :
	print(i%4,end =', ')
	i += 1

print((a-1)%4)
	
	