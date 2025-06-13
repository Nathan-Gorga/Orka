CC=gcc
CFLAGS=-Wall -Wextra -std=c11

orka: orka.c
	$(CC) $(CFLAGS) -o orka orka.c

clean:
	rm -f orka