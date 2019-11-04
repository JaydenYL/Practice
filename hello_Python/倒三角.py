a= int(input())
n = 0
i = 0
j = 0
for n in range(a):
    for i in range(n):
        print(' ', end='')
    for j in range(2*a-2*n-1):
        print('#', end='')
    print('')



