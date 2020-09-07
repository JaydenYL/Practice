def asdfb(n, m) :
	return m//n if m%n == 0 else asdfb(m%n, n)
	
print(asdfb(27, 30))