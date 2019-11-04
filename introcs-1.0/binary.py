import sys
import stdio

n = int(sys.argv[1])
x =0
i = 0
a = []
while n > 0:
    a.append(n %2)
    i += 1
    n = n // 2

print(a)
b = len(a)
x = b-1
while x >= 0 :
    print(a[x],end='')
    x = x-1
print('')
