num_ls = [31, 41, 59, 26, 41, 58]

def InsertionSort(num_ls):
	i = 1
	while i < len(num_ls):
		key = num_ls[i]
		j = i - 1
		while (j >= 0) and num_ls[j] < key:
			num_ls[j+1] = num_ls[j]
			j -= 1
		num_ls[j+1] = key
		i += 1
	return num_ls

print(InsertionSort(num_ls))