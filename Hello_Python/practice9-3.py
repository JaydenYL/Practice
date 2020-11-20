class User():
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    def describe(self):
        print('The user is '+ self.firstname+' '+self.lastname+'.')

    def greet(self):
        print('Hello world and hello '+self.firstname+' '+self.lastname)

I = User('LIU', 'YU')

I.describe()
I.greet()

Friend = User("guangji", 'Huang')
Friend.describe()
Friend.describe()