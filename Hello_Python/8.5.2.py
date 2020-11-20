#使用任意数量的关键字实参

def profile(first, last, **user_info):
    profile = {}
    profile['firstname']=first
    profile['lastname'] = last
    for key,value in user_info.items():
        profile[key] = value
    return profile

lib = profile('albert', 'einstein',
              loction='princeton',
              field='Physics')
print(lib)

