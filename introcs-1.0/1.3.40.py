import sys
import stdio
import random

times = 10000
exp1 = 0
exp2 = 0
i = 0
for i in range(times):
    j = 1
    while j <= 6:
        a = random.randrange(0, 6)
        if a == 2:
            exp1 += 1
            break
        j += 1
#print(exp1)        


i = 0   
for i in range(times):
    j = 1
    num = 0
    while j <= 12:
        a = random.randrange(0, 6)
        if a == 2:
            num += 1
        if num == 2:
            exp2 += 1
            break
        j += 1

#print(exp2)
        

p_1 = exp1/10000      
p_2 = exp2/10000

#print(p_1)
#print(p_2)
stdio.writeln(p_1)
stdio.writeln(p_2)
