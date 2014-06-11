#
# Makefile
#

PREFIX = .
CC = gcc
CFLAGS = -Wall -ggdb -Werror -I$(PREFIX)/include -L$(PREFIX)/lib -lcs50 -lm
APP = hello mario_single mario_double credit greedy temp_convert float_math sizeof ASCII progress arg caesar vigenere sigma

.PHONY: all clean
all: $(APP)

$(APP): % : $(PREFIX)/src/%.c
	$(CC) $< $(CFLAGS) -o $(PREFIX)/bin/$@

clean:
	cd $(PREFIX)/bin; rm -f *.o *.out $(APP)

