class restaurant():
    def __init__(self,name, cuisine_type):
        self.name = name
        self.cuisine_type = cuisine_type
        self.number_serve = 0

    def describe(self):
        print('This restaurant named '+self.name+
              ' and the cuisine type is '+self.cuisine_type)

    def open(self):
        print(str(self.name).title()+' is opening.')

    def restaurant_guests(self):
        print('Now there are '+str(self.number_serve)+' people in the restaurant .')

    def update_numbers(self):
        population  = input('How many people are there ?')
        self.number_serve = population

ChuanCaiGuan = restaurant('MaLa Space', 'Hotpot')

ChuanCaiGuan.restaurant_guests()
ChuanCaiGuan.update_numbers()
ChuanCaiGuan.restaurant_guests()

