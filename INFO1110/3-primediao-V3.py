import math

def primesLessThan(N):
# boolen list to present whether the number is prime
# 'True' means it is prime
	seive = [True] * N
	
# number 0 and 1 will is not prime or composite number
	seive[0] = seive[1] = False
	
# Then we check each number from 2 to int(math.sqrt(N)).
# Why int(math.sqrt(N))?
# The Answer is that:
# For example: 2*6 = 12, 3*4 = 12, 4*3 = 12, 6*2 = 12 .
# The last 2 calculate is unnecessary, so we can only 
# count to int(sqrt(12)) which is 3.
	for i in range(2,int(math.sqrt(N))+1):
		
# if number 'i' is prime number, then 2*i is not, and 3*i is also not.
		if (seive[i]):
			
# range(2*i,N,i)
# the last parameter is used to present the step:
# j is 2*i at first, and step is i which means 
# next time j is equal to 3*i, and then 4*i until
# j reach N

			for j in range(2*i,N,i):
				seive[j] = False
#	ls = []
#	p = 2
#	while p < N:
#		if seive[p]:
#			ls.append(p)
#		p += 1
#	return ls
	return [p for p in range(2,N) if seive[p]]

print(primesLessThan(6))