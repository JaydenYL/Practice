def convert(n):
	if not isinstance(n, int):
		raise TypeError
	if n < 0:
		raise ValueError
	s = ''
	while n > 0:
		s = str(n%2) + s
		n //= 2
	return int(s)
	
print(convert(4))