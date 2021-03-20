#!/usr/bin/env python3

def sensors_model(A, r):
	list_of_group  = []
	temp_group = []
	temp_group.append(0)
	
	for i in range(1, len(A)):
		if A[i] - A[i-1] <= r:
			temp_group.append(i)
		else:
			list_of_group.append(temp_group)
			temp_group = [i]
	if temp_group:
		list_of_group.append(temp_group)
	
#	print(list_of_group)
	
	combination = []
	for each_group in list_of_group:
		print("each_group: ", each_group)
		i = 0
		while i < len(each_group) - 1:
			j = i + 1
			while j < len(each_group):
				combination.append([each_group[i], each_group[j]])
				j += 1
			i += 1
		
	return combination



ls = [1, 4, 5, 8, 9, 10, 12]
print(sensors_model(ls, 2))