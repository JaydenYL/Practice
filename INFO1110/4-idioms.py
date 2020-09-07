import sys

list = []
while True:
	a = int(input('Numbers: '))
	if a == 0:
		break
	list.append(a)

print('Your numbers were:')
i = 0
while i < len(list):
	print('{:.1f}'.format(list[i]))
	i += 1
	
if sys.argv[1] == '-sum':
	print('The sum of those numbers is {:.1f}'.format(sum(list)))

if sys.argv[1] == '-avg':
	print('The average of those numbers is {:.1f}'.format(sum(list)/(len(list))))