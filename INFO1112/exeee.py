import sys, os

print("Hello world")
path = "/usr/bin/python3"
os.execl(path, path, sys.argv[0])