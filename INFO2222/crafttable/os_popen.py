import os

p = os.popen("ping 10.86.226.32".strip())
while 1:
	s = p.read()
	if "timeout" not in s:
		print("Server down")
	else:
		print("server online")