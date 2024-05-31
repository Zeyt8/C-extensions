#include "cstring.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

string string_new_empty(void) {
    string s;
    s.length = 0;
    s.data = malloc(1);
    s.data[0] = '\0';
    return s;
}

string string_new_char(const char* data) {
    string s;
    s.length = strlen(data);
    s.data = malloc(s.length + 1);
    strcpy(s.data, data);
    return s;
}

void string_free(string* s) {
    free(s->data);
    s->data = NULL;
    s->length = 0;
}

void string_print(const string* s) {
    printf("%s\n", s->data);
}

void string_concat_string(string* s1, const string* s2) {
    s1->data = realloc(s1->data, s1->length + s2->length + 1);
    strcat(s1->data, s2->data);
    s1->length += s2->length;
}

void string_concat_char(string* s1, char c) {
    s1->data = realloc(s1->data, s1->length + 2);
    s1->data[s1->length] = c;
    s1->data[s1->length + 1] = '\0';
    s1->length++;
}

int string_find_string(const string* s, const string* sub) {
    char* found = strstr(s->data, sub->data);
    if (found == NULL) {
        return -1;
    }
    return found - s->data;
}

int string_find_char(const string* s, char sub) {
    char* found = strchr(s->data, sub);
    if (found == NULL) {
        return -1;
    }
    return found - s->data;
}

string string_substring(const string* s, size_t start, size_t end) {
    string sub;
    sub.length = end - start;
    sub.data = malloc(sub.length + 1);
    strncpy(sub.data, s->data + start, sub.length);
    sub.data[sub.length] = '\0';
    return sub;
}

int string_compare_string(const string* s1, const string* s2) {
    return strcmp(s1->data, s2->data);
}

int string_compare_char(const string* s1, const char* s2) {
    return strcmp(s1->data, s2);
}

void string_remove(string* s, size_t start, size_t end) {
    size_t length = end - start;
    memmove(s->data + start, s->data + end, s->length - end);
    s->length -= length;
    s->data = realloc(s->data, s->length + 1);
    s->data[s->length] = '\0';
}