import sys
import stdio
import random
import math

a = math.atan(-1)
b = random.uniform(-a,a)
x = math.cos(b)
y = math.sin(b)

stdio.writeln(x)
stdio.writeln(y)
stdio.writeln(x*x + y*y)
        
