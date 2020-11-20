#导入函数


def personal_info(first, last, **user_info):
    profile = {}
    profile['firstname']=first
    profile['lastname'] = last
    for key,value in user_info.items():
        profile[key] = value
    return profile