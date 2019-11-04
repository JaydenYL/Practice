class dog():
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def sit(self):
        print(self.name.title()+' is now sitting.')

    def roll_over(self):
        print(self.name.title()+' rolled over.')

my_dog = dog('Willie', 6)
your_dog = dog('Lucy', 3)

print('My dog is '+my_dog.name+'.')
print('Your dog is '+your_dog.name+'.')
print('--------------')

my_dog.sit()
your_dog.sit()
print('--------------')

print('My dog is '+str(my_dog.age)+' years old.')
print('Your dog is '+str(your_dog.age)+'years old.')