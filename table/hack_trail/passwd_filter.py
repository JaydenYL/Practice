#!/Library/Frameworks/Python.framework/Versions/3.8/bin/python3

raw_data = []
while True:
	try:
		tmp = input()
	except EOFError:
		break
	raw_data.append(tmp)
	
for line in raw_data:
	ls = line.split("\"")
	if(ls[1] == "\\n"):
		break
	if len(ls) == 3 and len(ls[1]) == 1 :
		print(ls[1], end="")
	else :
		print("invalid format")
		
print()