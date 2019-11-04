alist = input('Numbers: ')
if alist == '':
	print('No numbers have been given.')
else:
	
	blist = alist.split(', ')
	s = 0
	i = 0
	while i < len(blist):
		if blist[i].isdigit():
			s += int(blist[i])
		else :
			print('No numbers have been given.')
			exit()
		i += 1
	print('The total sum of the given numbers is {}.'.format(s))
