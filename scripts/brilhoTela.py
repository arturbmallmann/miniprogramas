#!/usr/bin/python3
# Author: Artur Bernardo Mallmann
# License: Make what you want, or pay me a beer!!!
# Version: 0.000.000.r1alphace
import sys
import math
args=sys.argv
#print (args[1:3]) listas como usar: https://youtu.be/W8KRzm-HUcc
class MyException(LookupError):
    '"my exception"'
    
class File():
    def __init__(self, path):
        try:
            self.file=open(path,'r+')
        except:
            raise MyException();
    def read(self):
        self.file.seek(0)
        return int(self.file.readline())
    def write(self,value):
        print('Write> '+str(value))
        self.file.seek(0)
        self.file.write(str(value)+'\n')
        self.file.flush()
    def increase(self):
        value=math.log(self.read())
        value+=.25
        if math.exp(value)>=1500:
            value=math.log(1500)
        print (value)
        self.write(int(math.exp(value)))
    def decrease(self):
        value=math.log(self.read())
        value-=.25
        if math.exp(value)<5:
            return
        print(value)
        self.write(int(math.exp(value)))
def getBright(filename):
    try:
        file=open(filename)
        num=int(file.readline())
        file.close()
        return num
    except:
        raise MyException();

    
def main():
    filename="/sys/class/backlight/intel_backlight/brightness"
#    filename="/home/artur/teste"
#value=getBright(file)
    print (filename)
    myFile=File(filename)
    
    value=myFile.read();
    print (value)


    for item in args:
        if item=='up':
            myFile.increase()
        elif item=='down':
            myFile.decrease()
            
if __name__=='__main__':
    main()
