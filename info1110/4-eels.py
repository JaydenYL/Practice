import sys

i = 1
list = []
while i <= len(sys.argv):
	list.append(sys.argv[i-1])
	i += 1
print(', '.join(ele) for ele in list)

count = i = 0
for i in list:
	if i == 'eel' or i == 'eels':
		count += 1

if count == 0:
	print('Where are the eels?')
if count == 1:
	print('There are a few eels here.')
if count > 1:
	print('Wow, there are so many eels here!')
		
