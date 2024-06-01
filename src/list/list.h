#pragma once

#include <stdlib.h>

#define INSERT_ERROR -1

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} list;

// Lifetime
list* list_new(int capacity, size_t element_size);
void list_free(list* list);
void list_clear(list* list);
// Access
#define list_get(type, list, index) ((type*)(list->data))[index]
#define list_set(list, index, value) ((typeof(value)*)(list->data))[index] = value
// Modification
int list_insert(list* list, size_t index, void* value);
void list_remove(list* list, size_t index);