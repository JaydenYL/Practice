import sys

def special_function(n):
	num_ls = [2, 1]
	r_ls = []
	i, j = 0, 1
	while i < n:
		r_ls.append(j)
		j += num_ls[i % 2]
		i += 1
	return r_ls

path = sys.argv[1]
with open(path, 'r') as f:
	lines = f.readlines()
print_ls = special_function(7)
i = 0
while i < len(lines):
	if print_ls[i] >= len(lines):
		break
	print(lines[print_ls[i]].strip())
	i += 1