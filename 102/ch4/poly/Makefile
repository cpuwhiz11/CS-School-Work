# Makefile for the list primitives 
#
#

addpoly : list.o listinterface.o polynomial.o main.o
	gcc -ansi -Wall -o addpoly list.o listinterface.o polynomial.o main.o

list.o : globals.h list.h list.c
	gcc -c -ansi -Wall list.c 

listinterface.o : polynomial.h listinterface.c
	gcc -c -ansi -Wall listinterface.c

polynomial.o : listinterface.h polynomial.c
	gcc -c -ansi -Wall polynomial.c

main.o : polynomial.h main.c 
	gcc -ansi -Wall -c main.c 



clean :
	rm -f *.o 
