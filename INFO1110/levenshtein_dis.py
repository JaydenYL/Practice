def minimum(a, b, c):
            return min(min(a, b), min(b, c))

def Levenstheit_dis(str_1, str_2):
    if len(str_2) == 0:
        return len(str_1)
    if len(str_1) == 0:
        return len(str_2)
    offset = 0 if str_1[-1] == str_2[-1] else 1
    print(str_1, str_2)
    return minimum(Levenstheit_dis(str_1[0:-1], str_2) ,\
                    Levenstheit_dis(str_1, str_2[0:-1]) ,\
                    Levenstheit_dis(str_1[0:-1], str_2[0:-1])
    ) + offset
    
print(Levenstheit_dis("user", "PrivateMessage"))