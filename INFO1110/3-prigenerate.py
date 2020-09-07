a = int(input('give a number: '))
#bolist = [True]*a
i = 2
count = 0
prime = []
while i < a:
	j = 2
	while j<= i:
		if j == i:
			prime.append(j)
			count += 1
			break
		if i %j == 0:
			break
		j += 1
	i += 1

#print('\n')
print('There are {} prime numbers less than {}, they are '.format(count, a),end = '')	
i = 0
while i < len(prime)-2:
	print('{}, '.format(prime[i]),end = '')
	i += 1
print(prime[len(prime)-1], end = '.')
