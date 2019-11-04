class car:
    def __init__(self,make,model,year):
        self.make = make
        self.model = model
        self.year = year

    def get_info(self):
        long_name = str(self.year)+' '+self.make+' '+self.model
        return long_name.title()

my_car = car('auti', 'a8', 2019)
print(my_car.get_info())
