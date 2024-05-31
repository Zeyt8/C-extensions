CC = gcc
CFLAGS = -Wall -I/usr/include/CUnit -I../../.
LDFLAGS = -lcunit

all: string_tests

string_tests: string_tests.c ../../src/string/cstring.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f string_tests