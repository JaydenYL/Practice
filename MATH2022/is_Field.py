#!/usr/bin/env python3

def has_multi_reverse(n, z):
	for i in range(0, z):
		if (i*n)%z == 1:
			return True
	return False

def is_Field(Z):

	for i in range(1, Z):
		if not has_multi_reverse(i, Z):
			return False
	return True


for i in range(2, 50):
	if is_Field(i):
		print("Z_{}".format(i))
		
