import socket, time

client_ip = ""

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)

try:
	sock.bind(("", 6023))
except:
	print("bind failed ")
	quit()
	
sock.listen(8)
while True:
	conn_sock, from_addr = sock.accept()
	print('connected')
	data = b''
	while True:
		recv_data = conn_sock.recv(1)
		if len(recv_data) == 0:
			break
		else:
			data += recv_data
	if data.decode('utf-8') == 'Hello Sever!' :
		client_ip = from_addr[0]
		
	print(data.decode('utf-8'))
	conn_sock.close()