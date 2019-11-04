# LIU YU
# 2019-8-31 11:13 GMT+10

a = input('')
result = [0]*10
i = 0
while i < len(a):   
	result[int(a[i])] += 1
	i += 1

i = 0
while i < 10:
	print('{}: {}'.format(i, result[i]))
	i += 1
	