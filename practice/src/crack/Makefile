#
# Makefile
#

PREFIX = ../..
CC = gcc
CFLAGS = -ggdb -Wall -Werror -lcrypt

.PHONY: all clean
all: crypt_word crack

crypt_word: crypt_word.c
	$(CC) crypt_word.c $(CFLAGS) -o crypt_word

crack: crack.c
	$(CC) crack.c $(CFLAGS) -o crack

clean:
	rm -f *.o a.out core crypt_word crack
