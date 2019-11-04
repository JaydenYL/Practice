# LIU YU
# 2019-8-31 11:25 GMT+10

while True:
	try:
		a = input()
		l = len(a)
		result = ''
		i = l - 1
		while i >=0 :
			result += a[i]
			i -= 1
		print(result)
	except EOFError as error:
		exit()