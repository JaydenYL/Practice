def creat_file(name, msg):
    desktop = '/Users/yu/Desktop/'
    full_path = desktop + name + '.txt'
    file = open(full_path, 'w')
    file.write(msg)
    file.close()
    print('Done')
creat_file('Hello', 'Hello World')
creat_file('2', 'asasasfdsfesfaw')