CC = gcc
CFLAGS = -g -Wall -Wno-deprecated -std=c99
LIBS = -lm 

all:ex1 ex2bissecao ex3bis ex4new ex5sassenfeld ex6jacobiA ex6jacobiD ex6gauss-seidelA ex6gauss-seidelD ex7jacobi ex7gauss-seidel gauss-jordan

ex1: ex1.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)

ex2bissecao: ex2bissecao.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex3bis: ex3bis.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)

ex4new: ex4new.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex5sassenfeld: ex5sassenfeld.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex6jacobiA:ex6jacobiA.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex6jacobiD:ex6jacobiD.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex6gauss-seidelA:ex6gauss-seidelA.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex6gauss-seidelD:ex6gauss-seidelD.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex7jacobi:ex7jacobi.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
ex7gauss-seidel:ex7gauss-seidel.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
gauss-jordan:gauss-jordan.o
	$(CC) $(CFLAGS) $< -o $@.run $(LIBS)
#ex6: ex6.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
#ex7: ex7.o
#	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
test: 
	exec ./gauss-jordan.run

clean:
	-rm -f *.o *.run
