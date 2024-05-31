CC = gcc
CFLAGS = -Wall -I/usr/include/CUnit -I../../.
LDFLAGS = -lcunit

all: list_int_tests list_float_tests list_double_tests list_char_tests list_void_ptr_tests

list_int_tests: list_int_tests.c ../../src/list/list.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

list_float_tests: list_float_tests.c ../../src/list/list.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

list_double_tests: list_double_tests.c ../../src/list/list.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

list_char_tests: list_char_tests.c ../../src/list/list.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

list_void_ptr_tests: list_void_ptr_tests.c ../../src/list/list.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: all
	./list_int_tests
	./list_float_tests
	./list_double_tests
	./list_char_tests
	./list_void_ptr_tests

clean:
	rm -f list_int_tests list_float_tests list_double_tests list_char_tests list_void_ptr_tests