#   结合使用位置实参和任意数量实参
def make_pizza(size, *topping):
    print('Make '+str(size)+'-pizza with these topping:')
    for a in topping:
        print('-'+a)
make_pizza(13, 'mushrooms', 'green peppers')
make_pizza(16, 'pepperoni')

