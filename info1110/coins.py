x = int(input('input the amount of money: $ '))
money_ls = [100, 50, 20, 10, 5, 2, 1]
i = 0
while x != 0:
	if x //money_ls[i] > 0:
		print('{} x ${}'.format(x//money_ls[i], money_ls[i]))
		x %= money_ls[i]
	i += 1