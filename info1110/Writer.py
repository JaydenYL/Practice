def writer(filename, words):
	if not isinstance(filename, str) or not isinstance(words, list):
		raise TypeError
	for i in words:
		if not isinstance(i, str):
			raise ValueError
			
	f = open(filename, 'w')
	for i in words:
		f.write(i)
		f.write('\n')
		
friends = ["small bean", "big bean", "bean bag"]
writer("beans.txt", friends)