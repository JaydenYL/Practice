import time 
[(time.sleep(0.0009),  print("\033[91m"+i,end="",flush= 1)) for i in ('\n'.join([''.join([(' I love zyz'[(x-y)%15]if((x*0.05)**2+(y*0.1)**2-1)**3-(x*0.05)**2*(y*0.1)**3<=0 else' ')for x in range(-30,30)])for y in range(15,-15,-1)]))]

