WALL= -Wall -g
CC=gcc

all:libclassmat.a connections
connections: main.o libclassmat.a
	$(CC) $(WALL) -o connections main.o libclassmat.a

libclassmat.a:my_mat.o
	ar -rcs libclassmat.a my_mat.o 
my_mat.o:my_mat.c my_mat.o
	$(CC) $(WALL) -c my_mat.c
main.o:main.c my_mat.h
	$(CC) $(WALL) -c main.c
	
clean: 
	rm -f *.o *.a ./connections
