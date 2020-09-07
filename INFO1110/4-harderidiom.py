import sys

#process the list 
a = input('Enter some integers: ')
list1 = a.split(', ')
i = 0
while i < len(list1):
	list1[i] = int(list1[i])
	i += 1
print('Your integers were: {}'.format(list1))

#part1
def f8():
	i = 0
	while i < len(list1):
		if list1[i] == 8:
			print('The number 8 is at index {}'.format(i))
			break
		i += 1
	if i == len(list1):
		print('The number 8 is at index -1')

#part2
def even():
	i = 0
	ev = []
	while i < len(list1):
		if list1[i] % 2 == 0:
			ev.append(list1[i]//2)
		else:
			ev.append(list1[i])
		i += 1	
	print('Halve even numbers: {}'.format(ev))
	
#part3
def fac8():
	i = 0
	f8 = []
	while i < len(list1):
		if list1[i] % 8 == 0:
			f8.append(list1[i])
		i += 1
	print('Multiples of 8 are: {}'.format(f8))
	
#main			
if sys.argv[1] == '-find8':
	f8()
	
if sys.argv[1] == '-evens':
	even()
	
if sys.argv[1] == '-factor8':
	fac8()