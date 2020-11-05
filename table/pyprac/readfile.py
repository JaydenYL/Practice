with open("hello.txt", "r") as f:
	i = 0
	while i < 10:
		strr = f.readline()
		if strr:
			print(strr, end='')
		else :
			print("--------")
		i += 1