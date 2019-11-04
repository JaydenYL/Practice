#prctice8-14
#汽车

def make_car(name, brand, **other):
    car = {}
    car['name'] = name
    car['brand']=brand
    for key, value in other.items():
        car[key]=value
    return car
car = make_car('subaru', 'outback',
               color= 'blue',
               tow_package=True)

print(car)
