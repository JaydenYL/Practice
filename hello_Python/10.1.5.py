file_path = '/Users/yu/PycharmProjects/hello_Python/build/pi_million.txt'

with open(file_path) as file_object:
    lines = file_object.readlines()

pi_string = ''
for line in lines:
    pi_string += line

pi_string = pi_string.replace(' ','')

print(pi_string[:50+2],'\n')
print(len(pi_string))

birthday = input('Enter your birthday: ')
if birthday in pi_string:
    print('Your Birthday appears in the first 10 thousand digits of pi !')
else:
    print('sorry')