import sys
import stdio

n = int(sys.argv[1])

if n <0:
    stdio.writeln('INVALID INPUT')
else :
    for i in range(0, n+1):
        stdio.writeln(2**i)
