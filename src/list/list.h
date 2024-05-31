#pragma once

#include <stdlib.h>

#define PUSH_ERROR -1
#define INSERT_ERROR -1

#define DEFINE_LIST(name, type) \
    typedef struct { \
        type *data; \
        size_t size; \
        size_t capacity; \
    } list_##name; \
    \
    list_##name* list_##name##_new(int capacity); \
    void list_##name##_free(list_##name* list); \
    void list_##name##_clear(list_##name* list); \
    int list_##name##_insert(list_##name* list, size_t index, type value); \
    void list_##name##_remove(list_##name* list, size_t index); \
    int list_##name##_push(list_##name* list, type value); \
    void list_##name##_pop(list_##name* list);

DEFINE_LIST(int, int)
DEFINE_LIST(float, float)
DEFINE_LIST(double, double)
DEFINE_LIST(char, char)
DEFINE_LIST(void_ptr, void*)