#cosine.py
#YULIU
#2019.7.30

import sys
import stdio
import math

times = 24
x= float(sys.argv[1])*math.acos(-1)
cosx = 0
i = 0
while i <=times + 1:
    fac = 1
    j = 1
    t = 2*i
    #print(t)
    if t == 0:
        fac = 1
    else:
        while j <= t: 
            fac *= j
            j += 1
    #print(fac)
    an = (-1)**(i)*(x**t)/fac
    cosx += an
    i += 1
format = '%.6f\n'
stdio.writef(format,cosx)
    
    
