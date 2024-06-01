#include "list.h"

#include <string.h>

list* list_new(int capacity, size_t element_size) {
    list* new_list = malloc(sizeof(list));
    if (new_list == NULL) {
        return NULL;
    }
    new_list->data = malloc(capacity * element_size);
    if (new_list->data == NULL) {
        free(new_list);
        return NULL;
    }
    new_list->size = 0;
    new_list->capacity = capacity;
    new_list->element_size = element_size;
    return new_list;
}

void list_free(list* list) {
    free(list->data);
    free(list);
}

void list_clear(list* list) {
    list->size = 0;
}

int list_insert(list* list, size_t index, void* value) {
    if (index > list->size) {
        return INSERT_ERROR;
    }
    if (list->size == list->capacity) {
        list->data = realloc(list->data, list->capacity * 2 * list->element_size);
        if (list->data == NULL) {
            return INSERT_ERROR;
        }
        list->capacity *= 2;
    }
    memmove(list->data + (index + 1) * list->element_size, list->data + index * list->element_size, (list->size - index) * list->element_size);
    memcpy(list->data + index * list->element_size, value, list->element_size);
    list->size++;
    return 0;
}

void list_remove(list* list, size_t index) {
    if (index < list->size && list->size > 0) {
        memmove(list->data + index * list->element_size, list->data + (index + 1) * list->element_size, (list->size - index - 1) * list->element_size);
        list->size--;
    }
}