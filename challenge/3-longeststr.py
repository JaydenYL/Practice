# LIU YU
# 2019-8-30 23:34 GMT+10

word = []
l = []
print('Input 3 strings and find what string is the longest')
i = 0
while i < 3:
	a = input()
	word.append(a)
	l.append(len(a))
	i += 1

if l[0] ==l[1] == l[2] == 0:
	print('All strings are empty')
else:
	if l[0] ==l[1] == l[2]:
		print('All strings are the same length')
	else:
		lenth = ''
		i = 0 
		while i < 3:
			if l[i] > len(lenth):
				lenth = word[i]
			i += 1
		print('\"{}\" is the longest string'.format(lenth))
	