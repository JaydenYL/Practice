import time

n = int(input())

time1 = time.time()


b_checklist = [True] * (n + 1)
i = 2

th =1
while(th<=n):
	if th*th > n:
		break
	th += 1

while i < th:
	if b_checklist[i] == False:
		#NotImplemented
		i += 1
		continue
	j=i+i
	
	while(j<=n):
		b_checklist[j] = False
		j += i
	i += 1
		
counter = -2
for b in b_checklist:
	if b:
		counter += 1
time2 = time.time()	
print(counter)
print(time2 - time1)
	 
	
