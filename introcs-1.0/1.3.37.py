import sys
import stdio

times = 25
fac = 1
i = 1
sn = 1
x = float(sys.argv[1])

while i <= times:
    for j in range(1, i+1):
        fac = fac*j
    
    an = (x**i)/fac
    print(an)
    sn += an
    fac = 1
    j = 1
    i +=1

print(sn)


        
    
