class Person():
	counter = 0
	current_year = 2019
	is_christmas = False
	def __init__(self, full, year):		
		self.full_name = full if len(full.split()) > 1 else 'Guy Incognito'
		self.year = year if year > 0 else 2000
		Person.counter += 1
		self.id = self.counter
		
	def __str__(self):
		return '{}: {}, {}'.format(self.id, self.full_name, self.year)
		
	def get_age(self):
		return  self.current_year - self.year
		
	def get_friendly_name(self):
		return self.full_name.split()[0] + \
				(' ' + chr(0x1F384) if self.is_christmas else '')
	
	def celebrate_new_year():
		Person.current_year += 1
		Person.is_christmas = True
		
	def go_back_to_work():
		Person.is_christmas = False

		
print(Person.counter) # 0
x = Person.current_year # 2019
y = Person.is_christmas # False
print(x, y)

p = Person('Charles Montgomery Burns', 1937)
print(p.__str__()) # 1: Charles Montgomery Burns, 1937
print(p) # 1: Charles Montgomery Burns, 1937

print(Person.current_year) # 2019
print(Person.is_christmas) # False
print(p.get_age()) # 82
print(p.get_friendly_name()) # Charles

Person.celebrate_new_year()
print(Person.current_year) # 2020
print(Person.is_christmas) # True
print(p.get_age()) # 83
print(p.get_friendly_name()) # Charles 🎄

Person.go_back_to_work()
print(Person.current_year) # 2020
print(Person.is_christmas) # False
print(p.get_age()) # 83
print(p.get_friendly_name()) # Charles