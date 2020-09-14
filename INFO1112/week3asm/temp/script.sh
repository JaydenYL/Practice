#!/bin/bash
# 	Jayden 2020-09-14 20:30 AEST
#   the University of Sydney
#   INFO 1112 -- Week 3 Task 3

echo "Enter your project name please: "
read projname
mkdir $projname
cd $projname

#  make main.py
echo "def main():
	#Your main function here
	pass

if __name__ == \"__main__\":
	main()" 						> main.py

#  make test.py 	
echo "import unittest

class ${projname}Test(unittest.TestCase):
	def test_hello(self):
		hello = \"Hello World\"
		self.assertEquals(hello, \"Hello World\")


if __name__ == \"__main__\":
	unittest.main()" 				> test.py

#  make run.sh  and test.sh
echo "python3 main.py" 				> run.sh
echo "python3 test.py"				> test.sh


#  initialise a repository , add files and then commit
git init && git add --all && git commit -m "Project start"


#  THE END 
echo "\033[0;32mProject $projname ready! \033[0m"