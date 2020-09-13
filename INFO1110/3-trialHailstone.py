#a = int(input('A = '))
n = 18
alist = []
blist = []
alist.append(n)
while True:
	
	if n == 1:
		break
	elif n % 2 == 1:
		n = 3*n + 1
		alist.append(n)
	elif n%2 ==0 :
		n = n//2
		alist.append(n)
if len(alist) > len(blist):
	blist = []
	for i in alist:
		blist.append(i)

				
print(alist)		
#print(', '.join(str(j) for j in alist))