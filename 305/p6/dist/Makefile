# Makefile for assignment #6
# Paul Geromini
#
#

linker : linker.c
	gcc -ansi -Wall -o linker linker.c

run :
	./masm_MulRshDiv -o < main.asm > main.obj
	./masm_MulRshDiv -o < xbswt.asm > xbswt.obj
	./masm_MulRshDiv -o < rbswt.asm > rbswt.obj
	./linker main.obj xbswt.obj rbswt.obj > main.exe
	./mic1 prom_MulRshDiv.dat main.exe 0 2048

dump :
	./masm_MulRshDiv -o < main.asm > main.obj
	./masm_MulRshDiv -o < xbswt.asm > xbswt.obj
	./masm_MulRshDiv -o < rbswt.asm > rbswt.obj
	./linker -o main.obj xbswt.obj rbswt.obj 

clean :
	rm *.obj
	rm main.exe
	rm linker
