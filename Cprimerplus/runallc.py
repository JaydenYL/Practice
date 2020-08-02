import os;

ls = os.listdir();
print(ls, len(ls))

for i in ls:
	if len(i) > 2 and i[-2:] == ".c":
		os.system("gcc {}".format(i))
