#!/bin/env python3
# answer to Q4 
def solve(word):
	with open("/usr/share/dict/words", "r") as f:
		words = [i.strip("\n") for i in f.readlines()]
	
	for each_word in words:
		if len(each_word) != len(word):
			continue
		
		check , aim = list(word), list(each_word)
		while check:
			if check[0] in aim:
				if len(check) == 1 and len(aim ) == 1:
					return each_word
				aim.remove(check[0])
				check.remove(check[0])
				
			else:
				break
			
	return None

print(solve("nsaklbeat"))