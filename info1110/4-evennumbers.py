import sys

a = int(sys.argv[1])

if len(sys.argv) == 2:
	print('2\n4\n6')
else:
	b = int(sys.argv[2])
	i = 1
	while i <= 3:
		print(2*(b + i))
		i += 1
	