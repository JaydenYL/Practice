def make_pizza(size,*toppings):
    """"打印顾客所有的配料"""
    print('Make '+str(size)+' Pizza with :')
    for a in toppings:
        print('- '+a)
make_pizza(14,'a')
make_pizza(21,'a', 'b', 'c', 'd')
