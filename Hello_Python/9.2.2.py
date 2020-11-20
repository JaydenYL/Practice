class car:
    def __init__(self,make,model,year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer = 100

    def get_info(self):
        long_name = str(self.year)+' '+self.make+' '+self.model
        return long_name.title()

    def run_miles(self):
        print('\t\tThis car has '+str(self.odometer)+' miles on it.')

    def update_miles(self, mileage):
        #增加功能：禁止把里程表往回调

        if int(mileage) < int(self.odometer):
            print('You cannot roll back the opometer.')
        else :
            print('The odometer has updated !')
            self.odometer = mileage

    def increase_miles(self, mileage):
        self.odometer += int(mileage)

my_car = car('audi', 'a8', '2019')

#my_car.increase_miles(input('increase odometer by : '))
my_car.run_miles()

my_car.update_miles(input())
my_car.run_miles()
