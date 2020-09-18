# Jayden  2020-09-14 13:34 AEST

import sys

# a function that deal with escape key
escape_dict = [['\\n', '\\r', '\\t', '\\b'],
				['\n', '\r', '\t', '\b']]
				
def escape_key(arr):
	i = 0
	while i < 4:
		arr = arr.replace(escape_dict[0][i], escape_dict[1][i])
		i += 1
	return arr

# defensive checking 

if len(sys.argv) == 1:
	print("No arguments")
	sys.exit(3)
elif len(sys.argv) < 3:
	print("Not enough arguments")
	sys.exit(2)
elif len(sys.argv) > 3:
	print("Too many arguments")
	sys.exit(1)

#  validation				
raw, new = escape_key(sys.argv[1]), escape_key(sys.argv[2])

if (len(raw) != len(new)):
	print("Invalid arguments")
	sys.exit(0)


# main part

output = []

while True:
	try:
		string = input()
	except EOFError:
		break
	i = 0
	while(i < len(raw)):
		string = escape_key(string).replace(raw[i], new[i])
		i += 1
	output.append(string)

if output:
	print("\n".join(i for i in output))