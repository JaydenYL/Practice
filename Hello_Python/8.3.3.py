def make_shirt(color, size, character):
    print('The color of T-shirt is '+color+'. The size of the T-shirt is '+size+'.')
    print('The characcter on thr T-shirt is '+character+'.')
character = 'I love python'
colorlist = ['blue', 'yellow', 'white']
sizelist  = ['small', 'middle', 'large']
for a in colorlist:
    for b in sizelist:
        make_shirt(a, b, character)
        


#用类的方法完成一遍：-----------