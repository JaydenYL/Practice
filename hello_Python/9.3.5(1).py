from class_car import car
from class_electricalcar import electrical_car

class battery():

    def __init__(self, battery_volume = 70):
        self.battery_volume = battery_volume

    def descibe_battery(self):
        print('This car has a '+str(self.battery_volume)+' KWh battery .')

mytesla = electrical_car('Tesla ', 'Model s', '2019')

print(mytesla.describe_battery())
mytesla.descibe_battery()