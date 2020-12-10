#!/usr/bin/env python3
# Q 6

import socket

words = input("Enter a nine-letter word:")
if len(words) != 9:
	quit()
	
client = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)
client.connect(("localhost", 7070))
client.sendall(words.encode())
words = client.recv(1024)
print(words.decode())
client.close()