import string
class Restaurant():
	count = 0
	
	def __init__(self, name, restaurant_type):
		self.name = name
		self.restaurant_type = restaurant_type
#		self.number_served = number_served + 1
		Restaurant.count += 1

	
	def openRestaurant(self):
		print(self.name.title() + ' is open now.')
		
	def check_type(self):
		print('{} provides {}.'.format(self.name , self.restaurant_type))

practice = Restaurant('Little Asian', 'chinese food')

practice.openRestaurant()
practice.check_type()
print(Restaurant.count)

s = 'abc12!@#$%^&*()asf1234567890'
p = string.printable[ : -5]
print(p)