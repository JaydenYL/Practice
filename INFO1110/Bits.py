def most_popular(bin_str):
	if not isinstance(bin_str, str):
		raise TypeError
	count = [0, 0]
	i = 0
	while i < len(bin_str):
		if bin_str[i] == '0':
			count[0] += 1
		elif bin_str[i] == '1':
			count[1] += 1
		else:
			raise ValueError
		i += 1
	if count[0] == count[1]:
		return None
	return '1' if count[1] > count[0] else '0'
	
print(most_popular('101010010'))