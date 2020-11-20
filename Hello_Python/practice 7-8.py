sandwish = ['pastrami','hotdog','pastrami','hotdog3','pastrami', 'hotdog5']
finished = []
while sandwish:
    a = sandwish.pop()
    print('I am cooking '+a+' .')
    finished.append(a)
print('--------------\nfinished hotdog are follows :')
for a in finished:
    print(a)
print('\nNow, hotdogs are on sale\n')
print('Ohh, Pastrami are sold out!!!')
for a in finished:
    if a =='pastrami':
        finished.remove('pastrami')
print("So, these hordogs is on sale now:\n")
for a in finished:
    print(a, end=' ')
print('\n----------------\nE N D')
