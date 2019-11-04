class car():

    def __init__(self, make, model, year ):
        self.make = make
        self.model = model
        self.year = year
        self.odometer = 0

    def describe_car(self):
        long_name = str(self.year)+' '+self.make+' '+self.model
        return long_name.title()

    def read_odometer(self):
        print('This car has '+str(self.odometer)+' miles on it.')

    def update_odometer(self, mileage):
        if mileage < self.odometer:
            print('You cannot roll back the odometer !')
        else:
            print('The odometer has updated !')

    def increase_odometer(self, increment):
        self.odometer += increment

class electrical_car(car):

    def __init__(self, make, model,year):
        super().__init__(make, model, year)
        self.battery_volume = 70 # KWh

    def describe_battery(self):
        description = 'This car has a '+str(self.battery_volume)+' KWh battery . '
        return description.title()

my_tesla =electrical_car('tesla', 'model s', '2018')

print('---------------------------------------------------------------------------------------------------------------')
print(my_tesla.describe_car()+'\n')

print(my_tesla.describe_battery())