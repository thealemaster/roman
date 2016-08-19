CC=gcc -I ../include

CFLAGS=-Wall -c

all: roman_calculator.o
	$(CC) $(INCLUDES) $(CFLAGS) roman_calculator.c
	ar -rcs libroman_calculator.a roman_calculator.o
clean:
	$(RM) libroman_calculator.a roman_calculator.o
