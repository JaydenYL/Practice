num = int(input('Integer:'))
if ((num%2 == 0) and num <= 200 and num >= 20) or ((num%2 == 1) and num <0):
	print('{} passes the test!'.format(num))
else:
	print('{} fails the test :('.format(num))
