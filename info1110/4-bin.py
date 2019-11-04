a = str(input('Binary: '))
n = len(a)
i = 1
sum = 0
while i <= n:
	sum += int(a[-1*i])*2**(i-1)
	i += 1
print(sum)
	