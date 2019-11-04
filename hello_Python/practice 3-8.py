x = int(input())
c3 = [a**3 for a in range(x+1)]
print(c3)
for A in c3[:5]:
    print(A,  end= " ")
