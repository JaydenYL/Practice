import math
for i in range(10001):
    x = int(math.sqrt(i + 100))
    y = int(math.sqrt(i + 268))
    if (( x * x == i + 100) and ( y * y == i + 268)):
        print(x,y,i)

