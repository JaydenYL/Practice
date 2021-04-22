# Liu Yu
# 2021-04-22 09:46 AEST


with open("not_used_224.txt", "r") as f:
	lines = f.readlines()
	f.close()
out = []
for i in lines:
	if i not in out:
		out.append(i)

print("".join(out))

