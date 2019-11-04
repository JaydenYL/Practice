#Author: LIU YU
#2019-9-4 6:45 AEST

import sys
from function import process_file
from function import help
from function import terminate
from function import regular

day = 0
weekdays = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

# deal with regular transaction
if len(sys.argv) == 1:
	print('Error: Not enough command line arguments!')
	exit()
else:
	try:
		regular_balance = process_file(sys.argv[1])
	except ValueError as Error:
		print('Error: File not found!')
		exit()

# deal with start balance
try:
	start_balance = float(input('Starting balance: $'))
except ValueError as Error:
	print('Error: Cannot convert to float!')
	exit()
if start_balance <= 0:
	print('Error: Must start with positive balance!')
	exit()

# initialize current balance (money after a day) and start balance (money at the begin of a day)
current_balance = start_balance + regular_balance[0][day % 7] - regular_balance[1][day % 7]


# main function
while True:
	cmd = input('\nEnter command: ')
	
	# withdraw and deposit 
	if cmd == 'transaction':
		try:
			money = float(input('Enter amount: $'))	
			current_balance += money
		except ValueError as Error:
			print('Error: Cannot convert to float!')	

	# go to the next day
	elif cmd == 'next':
		day += 1
		start_balance = current_balance
		current_balance = start_balance + (regular_balance[0][day % 7] - regular_balance[1][day % 7] )
		if start_balance >= 0:
			print('Going to the next day...')	
		else:
			print('Oh no! You\'re in debt!')
			exit()
			
	# "How many money do I have ?"   --"You are in debt"	
	elif cmd == 'status':
		print('Day {} ({})'.format(day, weekdays[day % 7]))
		print('Starting balance: ${:.2f}'.format(start_balance))
		print('Current balance: ${:.2f}'.format(current_balance))
		if current_balance > start_balance:
			print('Nice work! You\'re in the black.')
		elif current_balance < start_balance:
			print('Be careful! You\'re in the red.')

	# fixed income and expenses
	elif cmd == 'regular':
		regular(regular_balance, weekdays)

	# the guide to help newbie
	elif cmd == 'help':
		help()

	# I donnot want to use this terminal-based shit 
	elif cmd == 'quit':
		terminate() 

	# Computer: " Pardon? "	
	else:
		print('Command not found.\nUse the "help" command for a list of available commands')
