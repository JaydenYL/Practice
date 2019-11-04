string = input('Enter a palindrome: ')
a = ''
for i in string:
	if i.isalpha():
		a += i.lower()

num = len(a)//2
p = True
i= 0
while i < num:
	if a[i] != a[len(a)-1-i]:
		p = not p
		break 
	i += 1
	
if not p:	
	print('\'{}\'is not a palindrome'.format(string))
else:
	print('\'{}\' is a palindrome'.format(string))
	
	