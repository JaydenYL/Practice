#!/usr/bin/env python3

class LoginManager() :
	
	def __init__(self):
		self.user_dict = {}
	
	
	def add_user(self, username, password):
		self.user_dict[username] = password
		
		
	def validate_user(self, username, password):
		try:
			return (password == self.user_dict[username])
		except:
			return False
	


mana = LoginManager()
mana.add_user("abcdefg", "1234567")
print(mana.validate_user("abcdefg", "1234567"))
print(mana.validate_user("abcdefg", "123456"), end="\v")
print(mana.validate_user("eweqe", "adfsg"))
