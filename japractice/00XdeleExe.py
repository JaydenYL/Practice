import os, time

def unKnowType(filename):
	return os.path.splitext(filename)[1] == ''

def isClass(filename):
	return False if len(filename) < 6 else filename[-6:] == '.class'

ls , remove_ls= os.listdir(), []

print("\033[31mSEARCHING\033[0m", end = '', flush= 1)
for i in range(0, 7):
	print("\033[31m.\033[0m", end = '', flush= 1)
	time.sleep(0.16)
print("\033.\033[0m\n")
for f in ls:
	name = os.path.splitext(f)[0]
	if (unKnowType(f) and (name+'.cpp' in ls or name+'.c' in ls )) or isClass(f):
		remove_ls.append(f)
		print("\033[37;44mREMOVING {}...\033[0m ".format(f))
		time.sleep(0.1)
		os.remove(f)
		
if remove_ls:		
	print('\n\033[32mFINISHED'+'-'*32+'\033[0m\n\nWe have successfully removed these file:\n')
	for i in remove_ls:
		print(i)
else:
	print('\n\033[1;30;47mNo Need to Clean  =)\033[0m')
	
print("\n")