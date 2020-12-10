#!/usr/bin/env python3
# Q5

import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(('', 7070))
serv.listen(5)
while True:
	conn, addr = serv.connect()
	recv_data = conn.recv(1024).decode()
	words = solve(recv_data)
	conn.sendall(words.encode())
	conn.close()