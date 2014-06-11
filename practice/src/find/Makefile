#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

PREFIX = ../..
CC = clang
CFLAGS = -ggdb3 -O0 -std=c99 -Wall -Werror -I$(PREFIX)/include -L$(PREFIX)/lib -lcs50 -lm

.PHONY: all clean
all: find generate

find: find.c helpers.c helpers.h
	$(CC) find.c helpers.c $(CFLAGS) -o find

generate: generate.c
	$(CC) generate.c $(CFLAGS) -o generate

clean:
	rm -f *.o a.out core find generate
