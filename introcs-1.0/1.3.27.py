import sys
import stdio

n = int(sys.argv[1])
a = 2*n -1
p = False

for i in range(a*n):
    p = not p
    if p:
        stdio.write('*')
    if not p:
        stdio.write(' ')
    if (i+1)%a == 0:
        stdio.write('\n')
