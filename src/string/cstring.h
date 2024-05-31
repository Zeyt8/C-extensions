#pragma once

#include <stddef.h>

typedef struct string {
    char* data;
    size_t length;
} string;

// Lifetime
#define string_new(s1) _Generic((s1), \
    char*: string_new_char, \
    default: string_new_empty \
)(s1)
string string_new_empty(void);
string string_new_char(const char* data);
void string_free(string* s);
void string_print(const string* s);

// Concatenation
#define string_concat(s1, s2) _Generic((s2), \
    const string*: string_concat_string, \
    char: string_concat_char \
)(s1, s2)
void string_concat_string(string* s1, const string* s2);
void string_concat_char(string* s1, char c);

// Find
#define string_find(s, sub) _Generic((sub), \
    const string*: string_find_string, \
    char: string_find_char \
)(s, sub)
int string_find_string(const string* s, const string* sub);
int string_find_char(const string* s, char sub);

// Substring
string string_substring(const string* s, size_t start, size_t end);

// Comparison
#define string_compare(s1, s2) _Generic((s2), \
    const string*: string_compare_string, \
    char*: string_compare_char \
)(s1, s2)
int string_compare_string(const string* s1, const string* s2);
int string_compare_char(const string* s1, const char* s2);

// Remove
void string_remove(string* s, size_t start, size_t end);