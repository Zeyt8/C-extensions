CC = gcc
CFLAGS = -Wall -I/usr/include/CUnit -I../../.
LDFLAGS = -lcunit
TESTS = list_tests

all: $(TESTS)

%_tests: %_tests.c ../../src/list/list.c ../../src/list/list_extensions.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TESTS)