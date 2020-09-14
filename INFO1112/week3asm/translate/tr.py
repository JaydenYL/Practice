# Jayden  2020-09-14 13:34 AEST

import sys

if len(sys.argv) == 1:
	print("No arguments")
	sys.exit(3)
elif len(sys.argv) < 3:
	print("Not enough arguments")
	sys.exit(2)
elif len(sys.argv) > 3:
	print("Too many arguments")
	sys.exit(1)
elif (len(sys.argv[1]) != len(sys.argv[2])):
	print("Invalid arguments")
	sys.exit(0)


raw, new = sys.argv[1], sys.argv[2]
output = []

while True:
	try:
		string = input()
	except EOFError:
		break
	i = 0
	while(i < len(raw)):
		string = string.replace(raw[i], new[i])
		i += 1
	output.append(string)

if output:
	print("\n".join(i for i in output))