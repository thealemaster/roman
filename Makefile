CC= gcc -I include

VPATH = lib test

# Compiler flags set to most strict
CFLAGS = -Wall -g

# Make sure the compiler knows where the libary lives
LIBFLAGS = -L./lib

# Libraries needed for this project (including the calculator library)
LIBS = -lrt -lm -lroman_calculator

# Make sure we have the right versions to support check

PKG_CONFIG = $(shell which pkg-config)
ifneq ($(PKG_CONFIG), "")
CFLAGS += $(shell $(PKG_CONFIG) --cflags check)
LIBS += $(shell $(PKG_CONFIG) --libs check)
endif

defaut : test

libroman_calculator.a: roman_calculator.o
	cd lib;make

check_roman_calculator.o: check_roman_calculator.c
	cd test;make

test:	check_roman_calculator.o libroman_calculator.a
	cd test;make
	cd lib;make
	$(CC) $(CFLAGS) -o check_roman_calculator test/check_roman_calculator.o -pthread $(LIBFLAGS) $(LIBS)

clean:
	-cd test;make clean
	-cd lib;make clean
	-rm check_roman_calculator  *.o


