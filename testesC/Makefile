CC=gcc
CFLAGS= -c -Wall -lm

all: lex

lex: re2c lex_an.o
	$(CC) lex_an.o -o lex.exec
re2c:
	re2c lex_an.re -o lex_an.c
lex_an.o: lex_an.c
	$(CC) $(CFLAGS) lex_an.c
debug:
	CFLAGS=${CFLAGS} -g
	all	
clean:
	rm -rf *.o *.exec
