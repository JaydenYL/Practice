x = int(input('input the amount of money: $ '))
money_ls = [100, 50, 20, 10, 5, 2, 1]
ls = []
m_ls = []
i = 0
while x != 0:
	if x //money_ls[i] > 0:
		ls.append(x//money_ls[i])
		m_ls.append(money_ls[i])
		x %= money_ls[i]
	i += 1
	
i = 0
while i < len(ls):
	print('{} x ${}'.format(ls[i], m_ls[i]))
	i += 1	