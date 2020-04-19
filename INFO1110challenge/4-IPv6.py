#LIU YU
#2019-8-31 09:50 GMT+10

ipv6 = (input('Please enter an IP address: ')).split(':')
if len(ipv6) != 8 :
	p = False
else:
	i = 0
	while i < 8 :
		if len(ipv6[i]) > 4:
			print('It is not a valid IPv6 address.')
			exit()
		i += 1
	mod = (int(ipv6[2], 16)+1) % 65536
	if mod == 0 or mod == 1:
		p = True
	else:
		p = False
		
if p:
	print('It is a valid IPv6 address.')
if not p:
	print('It is not a valid IPv6 address.')
