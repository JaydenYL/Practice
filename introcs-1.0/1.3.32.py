import sys

n = int(sys.argv[1])
s = int(n**(1/3))+1

for a in range(0 , s):
    for b in range(0, s):
        for c in range(0,s):
            for d in range(0,s):
                if a**3+b**3 == c**3+d**3 and a**3 + b**3 == n and :
                    print(a, b , c , d )
