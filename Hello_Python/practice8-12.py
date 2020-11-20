def sandwich_function(*topping):
    print('This sandwich is made of:')
    for i in topping:
        print('-'+i)
    print('')
sandwich_function('cheese','beef', 'lettuce')
sandwich_function('apple','banana', 'strawberry',)
sandwich_function('bread', 'lettuce', 'bacon', 'butter')