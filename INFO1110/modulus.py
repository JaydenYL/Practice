def modulus(num, div):
	if (type(num) != int) or (type(div) != int):
		raise TypeError
	return num % div
print(modulus(True, 1))