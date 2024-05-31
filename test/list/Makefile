CC = gcc
CFLAGS = -Wall -I/usr/include/CUnit -I../../.
LDFLAGS = -lcunit
TESTS = list_int_tests list_float_tests list_double_tests list_char_tests list_void_ptr_tests

all: $(TESTS)

%_tests: %_tests.c ../../src/list/list.c
    $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
    rm -f $(TESTS)