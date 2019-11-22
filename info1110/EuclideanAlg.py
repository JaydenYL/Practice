def max_factor(x, y):
	return max_factor(y, x%y) if y else x
print(max_factor(60, 12))