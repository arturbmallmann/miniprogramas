CC=g++
CFLAGS= -c -Wall

all:gs

gs:  opera.o main.o
		$(CC) main.o opera.o -o gs.bin
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

opera.o: opera.cpp
		$(CC) $(CFLAGS) opera.cpp

clean:
	rm -rf *.o gs.bin
