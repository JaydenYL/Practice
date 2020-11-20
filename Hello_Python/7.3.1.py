unconfirmed_user = ['Andy','Alice','Shi']
confirmed_user = []

while unconfirmed_user:
    current = unconfirmed_user.pop()
    print('Verifying User:'+ current.title())
    confirmed_user.append(current)
print('\nThe following user are confirmed')
for a in confirmed_user:
    print(a)
print('-----------------------')
for a in unconfirmed_user:
    print(a)