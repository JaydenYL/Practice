n = int(input('A = '))

while True:
	if n == 1:
		break
	if n % 2 == 1 and n != 1:
		n = 3*n + 1
		print(n, end = ', ')
	elif n%2 ==0 :
		n = n//2
		print(n, end=', ')
