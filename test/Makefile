CC=gcc -I ../include

CFLAGS = -c

PKG_CONFIG = $(shell which pkg-config)
ifneq ($(PKG_CONFIG), "")
CFLAGS += $(shell $(PKG_CONFIG) --cflags check)
endif

all:
	$(CC) $(CFLAGS) check_roman_calculator.c

clean:
	rm check_roman_calculator.o
