import base64, sys

def convertToImg(string, filepath):
	imgdata = base64.b64decode(string)
	f = open(filepath, 'wb')
	f.write(imgdata)
	f.close()
	return True

	
def convertToString(filepath):
	f = open(filepath, 'rb')
	string = base64.b64encode(f.read())
	f.close()
	return string	# [2: len(string) - 1]


if __name__ == '__main__':
	path = input("Enter the picture path: ")
	data = convertToString(path)
	print(data)
	path = input("Enter the new path to save the image: ")
	if path[0:4] == 'quit':
		sys.exit(1)
		
	if (convertToImg(data, path)):
		print("Successfully saved the image.")
	else :
		print("Fail in saving the picture.")