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