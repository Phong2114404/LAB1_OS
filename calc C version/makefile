CC = gcc
CFLAGS = -Wall -Werror

all: calc

calc: main.o calc.o
	$(CC) $(CFLAGS) -o calc main.o calc.o

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c main.c

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean:
	rm -f calc main.o calc.o