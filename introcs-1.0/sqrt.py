import sys
import stdio

MIN = 1e-15

c = float(sys.argv[1])
t = c
while abs(t-c/t)> (MIN*t):
    t = (c/t+t)/2

stdio.writeln(t)
