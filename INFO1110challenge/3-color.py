#LIU YU
#2019-8-31 00:19 GMT+10

pix1 = input('Please provide a pixel value: ')
pix2 = input('Please provide channel values or pixel value: ')

#covert hexadecimal to decimal
def convert_demi(para):
	pix = []
	if para[1] == 'x':
		j = 0
		while j < 3:
			pix.append(int(para[2*j+2:2*j+4], 16))
			j += 1
	else:
		para = para.split()
		j = 0
		while j < 3:
			pix.append(int(para[j]))
			j += 1
	return pix

# add to pixel together , underflow and overflow, covert to hexadecimal 
def new_pix(pix1, pix2):
	pix3 = []
	j = 0
	while j < 3:
		element = (pix1[j] + pix2[j]) % 256		# deal with underflow and overflow
		pix3.append(element)		
		j += 1
	new = ''
	j = 0
	while j < 3:
		pix3[j] = format(pix3[j], '02x') 	# '02x' and '03X' make difference in lower and upper case of hex
		new += pix3[j]
		j += 1
	return new

# main function
pix1 = convert_demi(pix1)
pix2 = convert_demi(pix2)
new = new_pix(pix1, pix2)
print('Your new pixel value is: 0x{}'.format(new))


