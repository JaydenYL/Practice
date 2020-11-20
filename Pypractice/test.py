import unittest
import random
import string
import subprocess

def rand_string(length=15):
	printable = string.printable[:-5]
	random_string = ''.join([
		printable[random.randint(
		0, len(printable) - 1
		)]
		for _ in range(length)
	])
	return random_string

global_key = rand_string()

class SampleTest(unittest.TestCase):
	
	def __init__(self, *args, **kwargs):
		self.class_key = rand_string()
		super().__init__(*args, **kwargs)
	
	
	def guess(self, process, key):
		
		guess = process.stdout.readline().decode('utf-8').strip('\n')
		response = "{guess} {{message}}".format(guess=guess)
		if guess == key:
			response = response.format(message="is correct!")
		else:
			response = response.format(message=self)
		process.stdin.write((response + '\n').encode())
		process.stdin.flush()
		return guess
	
	def key_check(self, key):
		process = subprocess.Popen('python pybreak.py'.split(),
						 stdin=subprocess.PIPE,
						 stdout=subprocess.PIPE
						)
		first_guess = self.guess(process, key)
		print(first_guess)
		
		second_guess = self.guess(process, key)
		print(second_guess)
		
		process.kill()
		if (key not in first_guess) and (key not in second_guess):
			self.assertIn(key, second_guess)
		return
			
	def test_global_key(self):
		global global_key
		key = global_key
		self.key_check(key)
		return
	 
	def test_class_key(self):
		key = self.class_key
		self.key_check(key)
		return           
	
	def __repr__(self):
		return "Is not the key!"
	
	
if __name__ == '__main__':
	unittest.main()