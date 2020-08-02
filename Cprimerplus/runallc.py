import os;

ls = os.listdir();
print(ls)

for i in ls:
	if len(i) > 2 and i[-2:] == ".c":
		os.system("gcc {} -o {}".format(i, i[:-2]))
