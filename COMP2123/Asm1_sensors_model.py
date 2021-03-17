#!/usr/bin/env python3

def sensors_model(A):
	group_list  = []
	temp_group = []
	temp_group.append(0)
	
	for i in range(1, len(A)):
		if A[i] - A[i-1] <= 2:
			temp_group.append(i)
		else:
			group_list.append(temp_group)
			temp_group = [i]
	if temp_group:
		group_list.append(temp_group)
	
	print(group_list)
	ret_list = []
	for each_group in group_list:
		print("each_group: ", each_group)
		i = 0
		while i < len(each_group) - 1:
			j = i + 1
			while j < len(each_group):
				ret_list.append([each_group[i], each_group[j]])
				j += 1
			i += 1
		
	return ret_list



ls = [1, 4, 5, 8, 9, 10, 12]
print(sensors_model(ls))