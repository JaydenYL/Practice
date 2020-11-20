num_ls = []
while True:
	num = int(input('Number: '))
	if num == 0:
		break
	num_ls.append(num)
	
length = len(num_ls)	
if length == 0:
	print('No integers were entered')
	quit()
	
remainder_ls = []
i = 0
while i < length:
	remainder_ls.append(num_ls[i] % 10)
	i += 1

max_re = 0
i = 0
while i < length:
	if max_re < remainder_ls[i]:
		max_re = remainder_ls[i]
	i += 1

ls_out = []
count = 0
i = 0
while i < length:
	if remainder_ls[i] == max_re:
#		bool_ls[i] == True
		count += 1
		ls_out.append(num_ls[i])
	i += 1

if count == length and count > 1:
	print('All integers have the same remainder')
elif count > 1:
	print('Two or more integers have the same remainder')
else:
	print('The most interesting integer is {}'.format(ls_out[0]))
	