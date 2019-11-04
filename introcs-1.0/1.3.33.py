import sys
import stdio

n = int(sys.argv[1])
a = []

for i in range(9):
    k = i +1
    a.append((n%(10**k))//(10**i))

s=0
j=2

for i in a:
    s += j*int(i)
    j += 1
    
print(s)

last = 11 - s%11

print(last)

