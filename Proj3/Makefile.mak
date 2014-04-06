CC = g++
CFLAGS = -Wall -c

Proj3.out: Proj3.o Proj3Aux.o Fraction.o
	$(CC) Proj3.o Proj3Aux.o Fraction.o -o Proj3.out

Proj3.o: Proj3.cpp
	$(CC) $(CFLAGS) Proj3.cpp
	
Proj3Aux.o: Proj3Aux.cpp Proj3Aux.h
	$(CC) $(CFLAGS) Proj3Aux.cpp

Fraction.o: Fraction.cpp Fraction.h
	$(CC) $(CFLAGS) Fraction.cpp

