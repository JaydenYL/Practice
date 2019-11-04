# Author: LIU YU
# 2019-10-01 AEST 14:09
from operator import truediv, mul, add, sub

numbers = input('Enter 4 integers: ')

def judgePoint24(A):
		if not A: return False
		if len(A) == 1: return abs(A[0] - 24) < 1e-6

		for i in range(len(A)):
			for j in range(len(A)):
				if i != j:
					B = [A[k] for k in range(len(A)) if i != k != j]
					for op in (truediv, mul, add, sub):
						if (op is add or op is mul) and j > i: continue
						if op is not truediv or A[j]:
							B.append(op(A[i], A[j]))
							if judgePoint24(B): return True
							B.pop()
		return False


num = numbers.split(' ')
try:
	if len(num) != 4:
		raise ValueError
	i = 0
	while i < len(num):
		num[i] = int(num[i])
		i += 1
except:
	print('\nInput must consist of 4 integers')
	exit()
		
Answer = judgePoint24( num )

if Answer:
	print('\nYes! 24 is reachable from {{ {}, {}, {}, {} }}'.format(num[0], num[1], num[2], num[3]))
else:
	print('\nNoooo :( 24 is unreachable from {{ {}, {}, {}, {} }}'.format(num[0], num[1], num[2], num[3]))