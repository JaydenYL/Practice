a = int(input('A = '))
init = 3
alist = []
blist = []
while init <= a :	
	n = init
	alist.append(n)
	while True:
		if n == 1:
			break
		if n % 2 == 1 and n != 1:
			n = 3*n + 1
			alist.append(n)
		elif n%2 ==0 :
			n = n//2
			alist.append(n) # should be ' ( ) ' ,rather than " [ ] "
#	print(alist)
	if len(alist) > len(blist):
		blist = alist.copy()
		
	alist = []
	init  += 1
	
#print(blist)

print(', '.join(str(j) for j in blist))

