a = int(input('A = '))

init = 3
alist = []
blist = []
while init <= a :	
	n = init
	alist.append(n)
	while (n != 1):
		if n % 2 == 1 :
			n = 3*n + 1
			alist.append(n)
		else :
			n //= 2
			alist.append(n) 
			
	if len(alist) > len(blist):
		blist = alist.copy()
		
	alist = []
	init  += 1
	

print(', '.join(str(j) for j in blist))

