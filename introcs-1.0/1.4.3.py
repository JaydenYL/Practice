import sys
import time
#n = int(sys.argv[1])
n = int(input())
time1 = time.time()
is_Prime = [True]*(n+1)

for i in range(2, n):
	if is_Prime[i]:
		t = n//i + 1
		for j in range(2, t):
			is_Prime[j*i] = False

count = 0
for i in range(2, n+1):
	if is_Prime[i]:
		count += 1
time2 = time.time()

print(count)
print(time2 - time1)