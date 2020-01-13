try:
	with open("transaction.txt", 'r') as f:
		lines = f.readlines()
except Exception:
	print("File not found!")
print('Saving Account'.center(37)+'\n'+'-'*38)
s = 0
for i in lines:
	s += float(i.split()[0])
	print(i.strip().split()[1].ljust(30), i.strip().split()[0].rjust(7))
print('-'*38+"\n{1} {0}".format(str(s).rjust(7), 'Total:'.ljust(30)))