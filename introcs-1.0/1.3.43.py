import sys
import stdio
import time

a = b = c = d = 1
#e = [n**5: n in range(250)]
e = 150

start = time.clock()
while a <= e:
    while b <= e:
        while c <= e:
            while d <= e:
                if a**5 + b**5 +c**5 +d**5 == 144**5:
                    print(a, b, c, d, e)
                    #elapsed = (time.time() - start)
                    #print(elapsed)
                d +=1
            c +=1
            d = c
        b += 1
        c = b
    a += 1
    b = a

#print('finish' + str(time.time() - start))
                    
