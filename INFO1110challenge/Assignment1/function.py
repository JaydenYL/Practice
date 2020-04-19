#porcess the file
def process_file(filename):
	try:
		f = open(filename, 'r')
		transaction_ls = f.readlines()
		f.close()
		i = 0
		while i < len(transaction_ls):
			transaction_ls[i].strip('\n')
			transaction_ls[i] = float(transaction_ls[i])
			i += 1
		f.close()
	except FileNotFoundError as Error:
		raise ValueError('Error: String does not represent a valid file!')
		
	income = []
	expenses = []
	i = 0 
	while i < len(transaction_ls):
		if i % 2 == 0:
			income.append(transaction_ls[i])
		else:
			expenses.append(transaction_ls[i])
		i += 1
	regular_b = (income, expenses)
	return regular_b


# print the regular transaction
def regular(tup, weekdays):
	i = 0
	print('Regular Transactions:')
	while i < 7:
		print('{}: +${:.2f} -${:.2f}'.format(weekdays[i], tup[0][i], tup[1][i]))
		i += 1

		
# instruction
def help():
	print('''The available commands are:
"transaction": Record a new income or expense
"next": Move on to the next day
"status": Show a summary of how you're doing today
"regular": Show a summary of your regular transactions
"help": Show this help message
"quit": Quit the program''')

	
# quit program
def terminate():
	print('Bye!')
	exit()