import sys

try:
	n = int(sys.argv[1])
except ValueError:
	print('Invalid input')
	quit()

i = 2
maxi = int(n**0.5)
while i <= maxi:
	if n % 2 == 0 :
		print('Not Prime')
		quit()
	i += 1
print('Is prime')