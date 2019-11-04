import sys

list = []
path = sys.argv[1]
a = sys.argv[2]
f = open(path, "r")

for line in f.readlines():
	list.append(line.strip(', \n'))

for i in list:
	if i[0] == a:
		print(i)
f.close()

