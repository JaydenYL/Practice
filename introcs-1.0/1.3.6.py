import sys
import stdio

n = int(sys.argv[1])
i = 1

while i <= n:
    if i%10 == 1:
        stdio.write(str(i)+'st ')
    elif  i%10 == 2:
        stdio.write(str(i)+'nd ')
    elif i%10 == 3:
        stdio.write(str(i)+'rd ')
    else :
        stdio.write(str(i)+'th ')
    stdio.writeln('hello world')
    i += 1
        
