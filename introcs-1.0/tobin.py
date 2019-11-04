import sys
import stdio

n = int(sys.argv[1]) #n进制
m = int(sys.argv[2]) #要转化的数

x =0
i = 0
yushu  = 0
a = []
while m > 0:
    if m%n < 10:
        yushu = m%n
    if m%n == 10 :
        yushu = 'A'
    if m%n == 11 :
        yushu = 'B'
    if m%n == 12 :
        yushu = 'C'
    if m%n == 13 :
        yushu = 'D'
    if m%n == 14 :
        yushu = 'E'
    if m%n == 15 :
        yushu = 'F'
    a.append(yushu)
    i += 1
    m = m // n


print(a)


b = len(a)
x = b-1
output = ''
while x >= 0 :
    stdio.write(a[x])
    output += str(a[x])   
    x = x-1

print('')
stdio.writeln(output)
