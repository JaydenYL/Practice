import stdio

for i in range (1000, 2000):
    stdio.write(str(i)+' ')
    if (i+1) % 5 == 0:
        stdio.write('\n')
