class Home():
	def  __init__(self, guests, room, bathr, wifi, cost):
		self.guests = guests
		self.room = room
		self.bathr = bathr
		self.wifi = wifi
		self.cost = cost
		
def compute_value(home):
	value = 10*(3*home.guests + home.room*home.room +  2* home.bathr + 50 * home.wifi)/home.cost
	return value
	
class Street():
	def __init__(self, places):
		self.places = places

		
	def get_worst_home(self):
		mini = 0
		index = -1
		i = 0
		while i < len(self.places):
			value = compute_value(self.places[i])
			if mini <  value:
				mini = value
				index = i
			i += 1
			
		if i == -1:
			return None
		return index
			
	
	def count_better_than(self, new_home):
		value = computer_value(new_home)
		count = 0
		i = 0
		while i < len(self.places):
			if compute_value(self.places[i]) > value:
				count += 1
			i += 1
		return count
