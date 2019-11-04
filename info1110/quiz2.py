# Author: LIU YU
# 2019-9-15 11:57 AEST

def letter_count(ls, typ):
	if (type(ls) != list) and (type(ls) != tuple):
		raise TypeError('First input is not a strig or tuple')
	i = 0
	while i < len(ls):
		if type(ls[i]) != str:
			raise InterruptedError('str is not a string!')
		i += 1
	if type(typ) != str:
		raise TypeError('String state str must be a string!')
	if typ != 'vowels' and typ != 'consonants':
		raise ValueError('String state may only be \'vowels\' or \'consonants\'.')	

	length = 0
	i = 0
	while i < len(ls):
		j = 0
		while j < len(ls[i]):
			if ls[i][j].isalpha(): 
				length += 1
			j += 1
		i += 1
		
	count = 0
	i = 0
	while i < len(ls):
		count += exits(ls[i])
		i += 1
	if typ == 'vowels':
		return count
	return length - count
	
		
def exits(elemn):
	check_ls = ['a', 'e', 'i', 'o', 'u']
	count = 0
	i = 0
	while i < len(elemn):
		j = 0
		while j < 5:
			if elemn[i] == check_ls[j]:
				count += 1
				break
			j += 1
		i += 1
	return count


#test case
ls = ['hello',2, 23, 'my', 'name', 'is', 'Victor']
typ = 'vowels'
ls2 = ['asdf']
t2 = 'consonants'
print(letter_count(ls, typ))	
