#Makefile for assignment 3
#Paul Geromini
#
#

p3 : p3.asm
	./masm < p3.asm > p3.obj
	./mic1 prom.dat p3.obj 0 2048

clean :
	rm *.obj 
