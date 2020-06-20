import socket, time

#server_ip = input("enter server's IP: ")
server_ip = "132.232.112.207"


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)
try:
    sock.connect((server_ip, 6025))
except:
    print("Failed to connect the server!")

data = b""
while True:
    recv_data = sock.recv(1)
    if len(recv_data) == 0:
        break
    else:
        data += recv_data
sock.close()
print("ftp://{}/shares".format(data.decode("utf-8")))


#ftp://111.220.134.14/shares