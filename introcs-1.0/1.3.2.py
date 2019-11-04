import sys
import stdio
import math

a = float(sys.argv[1])
b = float(sys.argv[2])
c = float(sys.argv[3])

deta = b*b - 4*a*c

if deta < 0:
    print (' no real root')

else:
    x1 = (-b + math.sqrt(deta))/(2*a)
    x2 = (-b - math.sqrt(deta))/(2*a)
    stdio.writeln(x1)
    stdio.writeln(x2)
