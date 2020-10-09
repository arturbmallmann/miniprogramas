#!/usr/bin/python3
# Author: Artur Bernardo Mallmann
# Mail: arturbmallmann@gmail.com
# License: Make what you want, and if you want pay me a beer!!!
# Version: 0.000.000.r2alphace
import sys
import math
#print (args[1:3]) listas como usar: https://youtu.be/W8KRzm-HUcc
class MyException(LookupError):
    '"my exception"'
    
class File:
	def __init__(self, path):
		try:
			self.file=open(path)#,+r para escrita
			self.file.seek(0)
		except:
			raise MyException();
	def __iter__(self):
		return self
	def __next__(self):
		ret=self.read()
		if ret == '':	
			self.file.seek(0)
			raise StopIteration
		return ret 
	def read(self):
		return self.file.readline()
	def write(self,value):
		print('Write> '+str(value))
		self.file.seek(0)
		self.file.write(str(value)+'\n')
		self.file.flush()
	def name(self):
		return self.file.name

