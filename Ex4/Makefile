CC=gcc
INCLUDE_DIR=.
CFLAGS= -std=c99 -Wall -g -I$(INCLUDE_DIR)

all: graph

graph: main.o
	$(CC) $(CFLAGS) edges.o nodes.o algo.o graph.o main.o -o graph

main.o: algo.o nodes.o edges.o graph.o main.c 
	$(CC) $(CFLAGS) -c main.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

edges.o: edges.c edges.h
	$(CC) $(CFLAGS) -c edges.c

nodes.o: nodes.c nodes.h
	$(CC) $(CFLAGS) -c nodes.c

algo.o: algo.c algo.h
	$(CC) $(CFLAGS) -c algo.c

clean:
	rm -rf *.o graph

clear:
	make.clean
