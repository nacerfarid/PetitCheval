CC = gcc --std=c99 -Wall -g -c
LD = gcc

PROG=serveur client
all: $(PROG)

clean:
	rm -f *~ *.o $(PROG)

client: client.o Reseau.o
	$(LD) -o client client.o Reseau.o

serveur: serveur.o Reseau.o
	$(LD) -o serveur serveur.o Reseau.o

client.o: client.c Reseau.h serveur.o
	$(CC) client.c
	
serveur.o: serveur.c Reseau.h
	$(CC) serveur.c
	
Reseau.o: Reseau.c Reseau.h
	$(CC) Reseau.c
