import random

name = str(input('Your name: ')).lower()
a,b = name.split()
n = a[0:2]+b[0:2]
number = random.randint(0000,9999)
print('{}{:04d}'.format(n,number))
