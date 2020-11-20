class restaurant():
    def __init__(self,name, cuisine_type):
        self.name = name
        self.cuisine_type = cuisine_type

    def describe(self):
        print('This restaurant named '+self.name+
              ' and the cuisine type is '+self.cuisine_type)

    def open(self):
        print(str(self.name).title()+' is opening.')

TheRes = restaurant('Taiwan_Food', 'ChaoCai')

print('')
TheRes.describe()
print('--------------------------')
TheRes.open()

Res1 = restaurant('ChuanCai', 'La')
Res2 = restaurant('YueCai', 'QingDan')

print('\n')

TheRes.describe()
Res1.describe()
Res2.describe()

