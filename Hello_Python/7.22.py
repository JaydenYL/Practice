a = 'Tell mme somehting , I will give you feed back'
a += '\n(Enter quit to leave)'
message = ''
while message !='quit':
    message  = input(a)
    if message == 'quit':
        break
    else:
        print(message)