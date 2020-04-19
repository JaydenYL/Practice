# Author: LIU YU
# 2019-9-20 14:52 AEST

dna_ls = ['A', 'a', 'G', 'g', 'T', 't', 'C', 'c']
cpl_ls = ['T', 't', 'C', 'c', 'A', 'a', 'G', 'g']

dna = input('Enter strand: ')
if dna == '':
	print('\nNo strand provided.')
	exit()

cpl_strand = ''
i = 0
while i < len(dna):
	j = 0
	while j < 8:
		if dna[i] == dna_ls[j]:
			cpl_strand += cpl_ls[j]
			break
		j += 1
	if j == 8:
		cpl_strand += 'x'
	i += 1
print('\nComplementary strand is {}'.format(cpl_strand))

