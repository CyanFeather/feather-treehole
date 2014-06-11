#
# Makefile
#

PREFIX = ../..
CC = gcc
CFLAGS = -ggdb -Wall -Werror

memory_alloc: memory_alloc.c
	$(CC) memory_alloc.c $(CFLAGS) -o memory_alloc

.PHONY: clean
clean:
	rm -f *.o a.out core memory_alloc
