CC = gcc
CFLAGS = -g -Wall -Wno-deprecated -std=c99
LIBS = -lm 

all:ex1 ex5sassenfeld

ex1: ex1.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

#ex2: ex2.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
#ex3: ex3.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
#ex4: ex4.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
ex5sassenfeld: ex5sassenfeld.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
#ex6: ex6.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
#ex7: ex7.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
test: 
	exec ./ex5sassenfeld
clean:
	-rm -f *.o main
