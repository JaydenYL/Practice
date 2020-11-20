from class_car import  car
class electrical_car(car):

    def __init__(self, make, model,year):
        super().__init__(make, model, year)
        self.battery_volume = 70 # KWh

    def describe_battery(self):
        description = 'This car has a '+str(self.battery_volume)+' KWh battery . '
        return description.title()