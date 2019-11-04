import sys
import stdio
import math

#n = int(sys.argv[1])
n=100

m = 1
num = 0
while m <= n:
    i = 2
    while i < math.sqrt(n) + 1 :
    #while i < m :
        if m % i == 0 and m != i:
            num += 1
            break
        i += 1
    m += 1

#print(num)

prime = n- 1 -num
print(prime)
