CC=gcc

CFLAGS= -c -Wall

all: main

main: main.o camino.o grafo.o funcionesStrings.o funcionesFlujo.o generadorArchivo.o
	$(CC)  main.o camino.o grafo.o funcionesStrings.o funcionesFlujo.o generadorArchivo.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c
camino.o: camino.c
	 $(CC) $(CFLAGS) camino.c
grafo.o: grafo.c
	 $(CC) $(CFLAGS) grafo.c
funcionesStrings.o: funcionesStrings.c
	 $(CC) $(CFLAGS) funcionesStrings.c
funcionesFlujo.o: funcionesFlujo.c
	 $(CC) $(CFLAGS) funcionesFlujo.c
generadorArchivo.o: generadorArchivo.c
	 $(CC) $(CFLAGS) generadorArchivo.c

clean:
	rm -rf *o 

