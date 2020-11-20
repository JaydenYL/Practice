def fun(i ,n):
	while (i == n):
		print(' '*i +str(i))
		return
	print(' '*i +str(i))
	fun(i+1, n)
	print(' '*i +str(i))

n = int(input())
i = 0	
fun(i, n)
	x