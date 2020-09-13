import sys

def hailstones(n):
	if n == 1:
		return [1]
	return [n] + hailstones(3*n+1) if n%2 else [n] + hailstones(n//2)

n = int(sys.argv[1])	
ls = [1]	
i = 1
while i <= n:
	tmp = hailstones(i)
	if len(tmp) > len(ls) :
		ls = tmp
	i += 1

print(', '.join(str(j) for j in ls))