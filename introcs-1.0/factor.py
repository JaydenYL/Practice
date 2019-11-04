import sys
import stdio

x = int(sys.argv[1])

t = 2
y = x
while t*2 <= y :
    if x % t ==0:     
        stdio.write(str(t)+' ')
        x = x /t
        
    else:
        t +=1

stdio.writeln('')
