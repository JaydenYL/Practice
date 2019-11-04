# Author: LIU YU
# 2019-9-20 22:37 AEST

pre_mrna = input('Input strand: ') + '   '

mrna = ''
segm = ''
status = True
i = 0
while i < len(pre_mrna) - 3:
	if status:
		if pre_mrna[i: i+4] == 'GUGU':
			mrna += segm
			segm += 'GUGU'
			status = False
			i +=4
		else:
			segm += pre_mrna[i]
			i += 1
		
	else:
		if pre_mrna[i: i+4] == 'AGAG':
			segm = ''
			status = True
			i += 4
		else:
			segm += pre_mrna[i]
			i += 1
			
mrna += segm			
print('\nOutput is {}'.format(mrna))

