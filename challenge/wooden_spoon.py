winners = ['C. Capybara', 'C. Capybara', 'C. Capybara', 'A. Aardvark', 'F. Flamingo', 'E. Echidna', 'A. Aardvark']
losers = ['A. Aardvark', 'B. Badger', 'F. Flamingo', 'G. Goat', 'Bye', 'D. Dolphin', 'E. Echidna']
lines = [ 'C. Capybara d. A. Aardvark'
		, 'C. Capybara d. B. Badger'
		, 'C. Capybara d. F. Flamingo'
		, 'A. Aardvark d. G. Goat'
		, 'F. Flamingo d. Bye'
		, 'E. Echidna d. D. Dolphin'
		, 'A. Aardvark d. E. Echidna']

def find_loser(winners, losers, lines, ls):

	dict = {}
	for key in winners:
		dict[key] = dict.get(key, 0) + 1		
	for key in losers:
		dict[key] = dict.get(key, 0) + 0		
	
#find the winner of Final	
	num = 0
	for key in dict:
		if dict[key] > num:
			winner = key
			num = dict[key]			
#										--------------winner
#find the loser of Final
	vice = [[], []]
	times = dict[winner]
	for key in dict:
		if (dict[key] == times - 1):
			vice[0].append(key)
			
	i = 0	
	while i < len(winners):
		if winners[i] == winner:
			vice[1].append(losers[i])
		i += 1
		
	for _ in vice[0]:
		if _ in vice[1]:
			loser = _		#---------------------loser
			
	for _ in lines:
		if (loser in _) and (winner in _):
			ls.append(_)
			
	while (loser in winners):
		winner = loser
		times = dict[winner]
		vice = [[], []]
		for key in dict:
			if (dict[key] == times - 1):
				vice[0].append(key)
				
		i = 0	
		while i < len(winners):
			if winners[i] == winner:
				vice[1].append(losers[i])
			i += 1
			
		for _ in vice[0]:
			if _ in vice[1]:
				loser = _    #---------------------loser
		
		for _ in lines:
				if (loser in _) and (winner in _):
					ls.append(_)
								
	return loser


match_ls = []
loser = find_loser(winners, losers, lines, match_ls)


l = len(match_ls) 
ls_out = []
i = 0
while i < l:
	ls_out.append(match_ls[l - i - 1])
	i += 1
	

if loser == 'Bye':
	print('No one wins the wooden spoon.')
else:
	print("{} wins the wooden spoon!\n".format(loser))
	ls = ['QF: ', 'SF: ', 'F: ']
	if l > 3:
		i = 1
		while l > 3:
			print('R{}: {}'.format(i, ls_out[i - 1]))
			i += 1
			l -= 1
	i = 0
	while l > 0:
			print('{}{}'.format(ls[-1*l], ls_out[-1*l]))
			l -= 1