people = [
	('Alice', 32),  # one tuple
	('Bob', 51),    # another tuple
	('Carol', 15),
	('Dylan', 5),
	('Erin', 25),
	('Frank', 48)
]
i= 0
yuanzu = (' ', 999)
while i < len(people):
	if people[i][1] <= yuanzu[1]:
		yuanzu = people[i]
	i += 1
	
print('Youngest person: {}, {} years old. '.format(yuanzu[0], yuanzu[1]))

print(people(people[i][1] == 5))