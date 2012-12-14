# Makefile for assignment 5
# Paul Geromini 
#
#

p5: main.o bestFit.o firstFit.o buddySys.o utility.o
	gcc -o p5 main.o bestFit.o firstFit.o buddySys.o utility.o 

main.o: main.c main.h
	gcc -c main.c

bestFit.o: bestFit.c main.h
	gcc -c bestFit.c

firstFit.o: firstFit.c main.h
	gcc -c firstFit.c

buddySys.o: buddySys.c main.h
	gcc -c buddySys.c

utility.o: utility.c main.h
	gcc -c utility.c

clean:
	rm *.o
	rm p5
