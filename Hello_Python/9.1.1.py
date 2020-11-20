class dog():

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def sit(self):
        print(self.name.title()+' is now sitting.')

    def roll_over(self):
        print(self.name.title()+' rolled over.')

    def eat_dog_meat(self):
        print('I love eat dog meat :)')

my_dog = dog('Peter', 6)
her_dog = dog ('Kitty', 4)
my_dog.sit()
my_dog.roll_over()
print('')

print('My dog is '+my_dog.name.title()+'.')
print('My dog is '+str(my_dog.age)+' years old.')
print('')

my_dog.roll_over()
her_dog.roll_over()