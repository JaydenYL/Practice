#在函数中修改列表

Tshirt = ['color', 'size', 'style']
clothes = []
def T(Tshirt, clothes):

    while Tshirt:
        clothes.append(Tshirt.pop())
    return clothes
print(T(Tshirt, clothes))
