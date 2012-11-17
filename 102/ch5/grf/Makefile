# Makefile for Graphical Region Fill.
#
#

grf : main.o image.o stackinterface.o stack.o
	gcc -ansi -Wall -o grf -g main.o image.o stackinterface.o stack.o

main.o : main.c 
	gcc -ansi -Wall -c -g main.c

image.o : image.h image.c
	gcc -ansi -Wall -c -g image.c

stackinterface.o : stackinterface.h stackinterface.c 
	gcc -ansi -Wall -c -g stackinterface.c

stack.o : stack.h stack.c
	gcc -ansi -Wall -c -g stack.c 

clean :
	rm -f *.o ;
