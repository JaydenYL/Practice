import sys
import random
import stdio

n = int(sys.argv[1])
rdm = []
i = 0

for i in range(n):
    if i == 0:
        a = maxi = mini = (random.random())
    else:
        a = random.random()
        stdio.writeln(a)
        if a > maxi:
            maxi = a
        if a < mini:
            mini = a
        
stdio.writeln('the maximum value is' + str(maxi))
stdio.writeln('The minimum value is' + str(mini))





'''
for i in range(len(rdm)) :
    if float(a[i-1])< float(a[i]):
        maxi = a[i]
print('---------------------\n' + str(maxi))


print(max(a))
        

stdio.writeln('maximum = '+index(max(a)))
stdio.writeln('minimum = '+index(min(a)))
'''
