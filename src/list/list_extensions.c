#include "list_extensions.h"

#include <string.h>

int list_push(list* list, void* value) {
    if (list->size == list->capacity) {
        list->data = realloc(list->data, list->capacity * 2 * list->element_size);
        if (list->data == NULL) {
            return PUSH_ERROR;
        }
        list->capacity *= 2;
    }
    memcpy(list->data + list->size * list->element_size, value, list->element_size);
    list->size++;
    return 0;
}

void list_pop(list* list) {
    if (list->size > 0) {
        list->size--;
    }
}

void list_remove_optimized(list* list, size_t index) {
    if (index < list->size && list->size > 0) {
        memcpy(list->data + index * list->element_size, list->data + (list->size - 1) * list->element_size, list->element_size);
        list->size--;
    }
}