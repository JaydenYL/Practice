#! /Library/Frameworks/Python.framework/Versions/3.9/bin/python3
# -*- coding: utf-8 -*-

print("Enter the vector: ")
a = [float(i) for i in input().strip().split(" ")]
b = [float(i) for i in input().strip().split(" ")]

if len(a) != len(b):
	print("They are not in the same dimension")
	quit()
	
dot_product = sum([i*j for i in a for j in b])


print("ab:", dot_product)

cross_product = [0, 0, 0]
cross_product[0] = a[1]*b[2] - a[2]*b[1]
cross_product[1] = a[2]*b[0] - a[0]*b[2]
cross_product[2] = a[0]*b[1] - a[1]*b[0]


print("axb: ", cross_product)

