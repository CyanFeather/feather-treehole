#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

PREFIX = ../..
CC = clang
CFLAGS= -ggdb3 -O0 -std=c99 -Wall -Werror -I$(PREFIX)/include -L$(PREFIX)/lib -lcs50 -lm

fifteen: fifteen.c
	$(CC) fifteen.c $(CFLAGS) -o fifteen

.PHONY: clean
clean:
	rm -f *.o a.out log.txt core fifteen
