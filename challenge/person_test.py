from family_tree import Person

arthur = Person("Arthur")
arthur.dies()
print(arthur.count_living_descendants())

fre = Person('fre')
fre.add_child(Person('AAA'))
fre.dies()

arthur.add_child(fre)



print(arthur.count_living_descendants())