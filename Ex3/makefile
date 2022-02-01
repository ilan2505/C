WALL= -Wall -g
CC=gcc

all:libclassfunc.a stringProg
stringProg: main.o libclassfunc.a
	$(CC) $(WALL) -o stringProg main.o libclassfunc.a

libclassfunc.a:my_func.o
	ar -rcs libclassfunc.a my_func.o 
my_func.o:my_func.c my_func.o
	$(CC) $(WALL) -c my_func.c
main.o:main.c my_func.h
	$(CC) $(WALL) -c main.c
	
clean: 
	rm -f *.o *.a ./stringProg
