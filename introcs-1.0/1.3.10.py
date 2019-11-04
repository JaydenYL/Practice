import sys
import stdio
import math

a = 1
for a in range(11):
    n = 2**a
    print( math.log(n,2), math.log(n), n*n, n**3, 2**n)
    a +=1
