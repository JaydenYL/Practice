import math

def primesLessThan(n):
	b_checklist = [True] * (n + 1)
	k = math.sqrt(n)
	i = 2
	while i < k:
		if b_checklist[i] == False:
			i += 1
			continue
		j=i+i
		
		while(j <= n):
			b_checklist[j] = False
			j += i
		i += 1
	return [p for p in range(2,n) if b_checklist[p]]
	
print(len(primesLessThan(100)))