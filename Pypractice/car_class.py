class car():
	
	def __init__(self, make, model, year):
		self.make = make
		self.model = model
		self.year = year
		self.odometer = 20
		
	def describe(self):
		full_info = str(self.year) + ' ' + self.make + ' ' + self.model
		return full_info
		
	def read_odom(self):
		print('This car has {} miles on it.'.format(self.odometer))
		
	def update_odom(self, miles):
		if miles < self.odometer:
			print('Error : cannot roll back the odometer!')
		else:
			self.odometer = miles
	
	
mycar = car('Audi', 'A8', 2019)

