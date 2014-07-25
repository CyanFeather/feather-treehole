#
#  Makefile
#

CC=gcc
CFLAGS=-Wall -std=c99
OUT=memory

.PHONY: all clean
all: $(OUT)

$(OUT): %: %.c
	$(CC) $< $(CFLAGS) -o $@

clean:
	rm -f *.o *.out *~ $(OUT)
