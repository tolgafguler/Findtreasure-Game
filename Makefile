CC = gcc

CFLAGS = -c -Wall

all: findtreasure

findtreasure: findtreasure.o
	$(CC) findtreasure.o -o findtreasure

findtreasure.o: findtreasure.c
	$(CC) $(CFLAGS) findtreasure.c
	
run:
	./findtreasure 18x18 3 mapmatrix.txt keymatrix.txt output.txt
	
clean: 
	rm -rf *o findtreasure
