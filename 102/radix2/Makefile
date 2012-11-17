# Makefile for Radix Sort
#
#

radix : radixsort.o list.o numberinterface.o 
	gcc -ansi -Wall -o radix -g radixsort.o list.o numberinterface.o

radixsort.o : radixsort.c
	gcc -ansi -Wall -c -g radixsort.c

list.o : list.c list.h
	gcc -ansi -Wall -c -g list.c 

numberinterface.o : numberinterface.h numberinterface.c 
	gcc -ansi -Wall -c -g numberinterface.c 

clean : 
	rm -f *.o
