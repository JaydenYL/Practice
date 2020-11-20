import time , os
from random import randint
from collections import deque

snow_ls = deque(maxlen = 15)
i = 0
while i < 36:
	snow_ls.appendleft([' ']*100)
	i += 1

i = 0
while True:
	os.system('clear')
	ls = [' ']*100
	a = randint(0, 6)
	j = 0
	while j < a:
		b = randint(0, 98)
		if ls[b - 1] == ' ' and ls[b + 1] == ' ':
			ls[b] = '*'
		j += 1
	snow_ls.appendleft(ls)
	try:
		snow_ls[-4][14] = snow_ls[-3][13] = '/'
		snow_ls[-4][15] = snow_ls[-3][16] = '\\'
		snow_ls[-3][14] = snow_ls[-3][15] = snow_ls[-2][14] =snow_ls[-2][15] = snow_ls[-1][15] = snow_ls[-1][14] = ' '
		snow_ls[-2][16] = snow_ls[-1][16] = snow_ls[-2][13] = snow_ls[-1][13] = '|'
		snow_ls[-1][i + 0: i + 12] = ' -O-------O-'
		snow_ls[-2][i + 0: i + 13] = '| [] [] [] L|'
		snow_ls[-3][i + 0: i + 13] = '-------------'
	except:
		pass
	i += 1
	i = i % 87
	for k in snow_ls:
		for l in k:
			print(l, end = '')
		print()
	print('-' * 100)
	time.sleep(0.08)
	
	
'''
-------------
| [] [] [] L|
 -O-------O-
'''

'''
	snow_ls[11][14] = snow_ls[12][13] = '/'
	snow_ls[11][15] = snow_ls[12][16] = '\\'
	snow_ls[12][14] = snow_ls[12][15] = snow_ls[13][14] =snow_ls[13][15] = snow_ls[14][15] = snow_ls[14][14] = ' '
	snow_ls[13][16] = snow_ls[14][16] = snow_ls[13][13] = snow_ls[14][13] = '|'
'''