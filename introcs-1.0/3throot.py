import sys
import stdio

MIN = 1e-10

c = float(sys.argv[1])
t = c

while abs(t - c/(t*t)) > MIN*t:
    t = (c/(t*t) +2*t)/3

stdio.writeln(t)
