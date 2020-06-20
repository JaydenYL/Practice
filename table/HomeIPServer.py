import threading, socket, time, copy

client_ip = ""
mutex = threading.Lock()

class Raspberry(threading.Thread) :
	
	def __init__(self):
		self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)
		
		threading.Thread.__init__(self)
		
		
	def run(self):
		global client_ip, mutex
		try:
			self.sock.bind(("", 6023))
		except:
			print("bind failed ")
			return
			
		self.sock.listen(8)
		while True:
			self.conn_sock, self.from_addr = self.sock.accept()
			self.data = b''
			while True:
				self.recv_data = self.conn_sock.recv(1)
				if len(self.recv_data) == 0:
					break
				else:
					self.data += self.recv_data
			if self.data.decode('utf-8') == 'Hello Sever!' :
				mutex.acquire()
				client_ip = copy.deepcopy(self.from_addr[0])
				mutex.release()
				
			self.conn_sock.close()
			
			
			
class PC(threading.Thread) :

	def __init__(self):
		
		self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)
		
		threading.Thread.__init__(self)
		
		
	def run(self):
		global client_ip, mutex
		try:
			self.sock.bind(("", 6025))
		except:
			print("bind failed ")
			return
	
		self.sock.listen(8)

		while True:
			self.conn_sock, self.from_addr = self.sock.accept()
			mutex.acquire()
			self.data = copy.deepcopy(client_ip)
			mutex.release()
			self.conn_sock.send(self.data.encode('utf-8'))
			self.conn_sock.shutdown(socket.SHUT_RDWR)
			self.conn_sock.close()
			

threads = []
threads.append(Raspberry())
threads.append(PC())

for i in threads :
	i.setDaemon(True)
	i.start()


for i in threads :
	i.join()