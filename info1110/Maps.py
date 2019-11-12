class Pair():
	def __init__(self, key, value):
		self.key = key
		self.value = value
		
class Dictionary():
	def __init__(self):
		self.items = []
		
	def __setitem__(self, key, value):
		i = 0
		while i < len(self.items):
			if self.items[i].key == key:
				self.items[i].value = value
				return
			i += 1
		new_pair = Pair(key, value)
		self.items.append(new_pair)
		
	def __contains__(self, key):
		i = 0
		while i < len(self.items):
			if self.items[i].key == key:
				return True
			i += 1
		return False
			
	def __getitem__(self, key):
		i = 0
		while i < len(self.items):
			if self.items[i].key == key:
				return self.items[i].value
			i += 1	
		raise KeyError
		
	def __len__(self):
		return len(self.items)

		
		

p1 = Pair('iteration', 'visiting each element in a collection') 
print(p1.key) # iteration
print(p1.value) # visiting each element in a collection
p2 = Pair('recursion', 'recursion') 
print(p2.key) # recursion 
print(p2.value) # recursion
print('------------------------------------------------------')
d1 = Dictionary() 
print(d1.items) # []
d1.__setitem__('iteration', 'visiting each element in a collection')
print(d1['iteration'])
d1['iteration'] = 'traversing a collection or range'
print(d1['iteration'])
d1['recursion'] = 'recursion'
print(len(d1))