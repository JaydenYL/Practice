for a in range(1, 21):
    print(a, end=' ')

million = []
for a in range(1, 1000001):
    million.append(a)
print(min(million),'\n', max(million),'\n', sum(million))
print(int(min(million)))