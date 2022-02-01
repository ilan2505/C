CC= gcc

all: loops recursives  recursived loopd mains maindloop maindrec 


loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

mains: main.o libclassrec.a
	$(CC) -o mains main.o libclassrec.a -lm
maindloop: main.o
	$(CC) -Wall -g -o maindloop main.o ./libclassloops.so -lm
maindrec:  main.o
	$(CC) -Wall -g -o maindrec main.o ./libclassrec.so -lm
libclassloops.a : advancedClassificationLoop.o basicClassification.o
	ar -rcs libclassloops.a advancedClassificationLoop.o basicClassification.o
libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	ar -rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o
libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(CC) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o
libclassloops.so:  advancedClassificationLoop.o basicClassification.o
	gcc -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) -c advancedClassificationLoop.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) -c basicClassification.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) -c advancedClassificationRecursion.c
main.o: main.c NumClass.h
	$(CC) -c main.c 

clean:
	rm -f *.o *.a *.so maindloop mains maindrec
