#practice8-13
#用列表进行自我介绍

def profile(first, last, **user_info):
    profile = {}
    profile['firstname']=first
    profile['lastname'] = last
    for key,value in user_info.items():
        profile[key] = value
    return profile

dic = profile('LIU', "YU",
              favorite_subject='Physics',
              hobbit='reading',
              )
print(dic)