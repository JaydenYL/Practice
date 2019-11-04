class restaurant():

    def __init__(self,name, cuisine_type):
        self.name = name
        self.cuisine_type = cuisine_type

    def describe(self):
        print('This restaurant named '+self.name+
              ' and the cuisine type is '+self.cuisine_type)

    def open(self):
        print(str(self.name).title()+' is opening.')

class icecreamstand(restaurant):

    def __init__(self, favorite):
        super.__init__()
        self.favorite = favorite

        
