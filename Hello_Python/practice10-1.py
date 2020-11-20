with open('/Users/yu/PycharmProjects/hello_Python/build/learning_python.txt','w') as file_object:
    for i in range(4):
        file_object.write('In python I can '+input()+' .\n')

# 在open的时候一定要加'w'或者'a'，才可以写入。
# 前者将会对文件原来的内容进行覆盖，而后者这是在文件的末尾新增内容。
