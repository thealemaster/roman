CC=gcc -I ../include

CFLAGS=-Wall -c

# Make sure we have the right check, based on how it was installed
PKG_CONFIG = $(shell which pkg-config)
ifneq ($(PKG_CONFIG), "")
CFLAGS += $(shell $(PKG_CONFIG) --cflags check)
endif

all: roman_calculator.o
	$(CC) $(INCLUDES) $(CFLAGS) roman_calculator.c
	ar -rcs libroman_calculator.a roman_calculator.o
clean:
	$(RM) libroman_calculator.a roman_calculator.o
