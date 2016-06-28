CC=g++
CFLAGS= -c -Wall

all:rush

rush: main.o rush.o
		$(CC) main.o rush.o -o rush
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

rush.o: rush.cpp
		$(CC) $(CFLAGS) rush.cpp

clean:
	rm -rf *.o rush
