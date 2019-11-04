class User:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

    def describe(self):
        print('The user is '+ self.firstname+' '+self.lastname+'.')

    def greet(self):
        print('Hello world and hello '+self.firstname+' '+self.lastname)


class Admin(User):
    def __init__(self, firstname, lastname):
        super().__init__(firstname, lastname)
        self.privileges = ['can add post', 'can delete post', 'can ban user']

    def ShowPrivilges(self):
        for i in self.privileges:
            print("Admin "+i+'.', end='\n')


Admin1 = Admin('LIU', 'YU')
Admin1.ShowPrivilges()
Admin1.describe()