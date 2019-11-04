#禁止函数修改列表

def  T( Tshirt,clothes):

    while Tshirt:
        clothes.append(Tshirt.pop())

def showT(clothes):
    print('\n The follow Tshirt have been completed:')
    for a in clothes:
        print(a)

Tshirt = ['a','b', 'c']
clothes = []

T(Tshirt[:], clothes)
print(Tshirt)
showT(clothes)
