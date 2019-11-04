import sys
import stdio
import random
import math
n = int(sys.argv[1])
a = 0

for i in range(n):
    while True:
        x = -1.0 + 2*random.random()
        y = -1.0 + 2*random.random()
        a += 1
        if x*x +y*y <=1.0:
            break

    i +=1

stdio.writeln(str(i) + 'times')
stdio.writeln(4*i/a)
stdio.writeln(math.acos(-1))
    
