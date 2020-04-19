class Person():
	def __init__(self, name):
		self.name = name
		self.children = []
		self.is_alive = True
		
		
	def add_child(self, who):
		self.children.append(who)

	
	def dies(self):
		self.is_alive = False
		print('{} has died :('.format(self.name))

		
	def count_living_descendants(self):
#		if not self.children:
#			return 0 #if self.is_alive else -1
		s = 0
		i = 0
		while i < len(self.children):
			s += self.children[i].count_living_descendants()+\
					(1 if self.children[i].is_alive else 0) 
			i += 1
		return s 
#		s = 1 if self.is_alive else 0
#		if not self.children:
#			return s
#		i = 0 
#		while i < len(self.children):
#			s += self.children[i].count_living_descendants()
#			i += 1
#		return s


	def get_children_names(self):
		return [i.name for i in self.children]
#		name_ls = []
#		i = 0
#		while i < len(self.children):
#			name_ls.append(self.children[i].name)
#			i += 1
#		return name_ls
		
#--------------------------------------------------------------------
if __name__ == '__main__':
	#####################
	## Create a person ##
	#####################
	arthur = Person("Arthur")

	#####################
	## Adding children ##
	#####################
	arthur.add_child(Person("Bill"))
	arthur.add_child(Person("Charlie"))
	arthur.add_child(Person("Percy"))

	# (We can add children like this too)
	fred = Person("Fred")
	arthur.add_child(fred)

	george = Person("George")
	arthur.add_child(george)

	ron = Person("Ron")
	arthur.add_child(ron)

	ginny = Person("Ginny")
	arthur.add_child(ginny)

	#######################
	## Count descendants ##
	#######################
	print(arthur.count_living_descendants())
	# -> 7

	######################
	## List of children ##
	######################
	print(arthur.get_children_names())
	# -> ['Bill', 'Charlie', 'Percy', 'Fred', 'George', 'Ron', 'Ginny']

	##################
	## People dying ##
	##################
	fred.dies()
	# -> print "Fred has died :("

	print(arthur.count_living_descendants())
	# -> 6

	#############################
	## Adding more descendants ##
	#############################
	ron.add_child(Person("Rose"))
	ron.add_child(Person("Hugo"))

	ginny.add_child(Person("James"))
	ginny.add_child(Person("Albus"))
	ginny.add_child(Person("Lily"))

#	fred.add_child(Person('Anliaaaa'))

	print(arthur.count_living_descendants())
	# -> 11

	print(ginny.count_living_descendants())
	# -> 3