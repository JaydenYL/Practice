
def hailstones(n):
	if n == 1:
		return 1
	elif n % 2 == 1:
		return hailstones(3*n+1)
	else:
		return hailstones(n/2)
	
result = hailstones(int(input('A = ')))
print(result)

