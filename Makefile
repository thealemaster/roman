VPATH = lib test

# Compiler flags set to most strict
CFLAGS = -Wall -g

# Place where header files for this project will go
INCLUDES = -I./include

# Make sure the compiler knows where the libary lives
LIBFLAGS = -L./lib

# Libraries needed for this project (including the calculator library)
LIBS = -lcheck_pic -lrt -lm -lroman_calculator

defaut : test

libroman_calculator.a: roman_calculator.o
	cd lib;make

check_roman_calculator.o: check_roman_calculator.c
	cd test;make

test:	check_roman_calculator.o libroman_calculator.a
	cd test;make
	cd lib;make
	gcc $(CFLAGS) $(INCLUDES) -o check_roman_calculator test/check_roman_calculator.o -pthread $(LIBFLAGS) $(LIBS)

clean:
	-cd test;make clean
	-cd lib;make clean
	-rm check_roman_calculator  *.o


