import sys
import stdio

MIN = 1e-15

n = float(sys.argv[1])
c = float(sys.argv[2])
t = c

while abs(1 - c/(t**n)) > MIN:
    a = t**(n-1)
    b = c/a
    d = (n-1)*t
    t = (b + d)/n

stdio.writeln(t)
