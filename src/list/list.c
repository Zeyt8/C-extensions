#include "list.h"

#include <stdlib.h>

#define DEFINE_LIST_FUNCTIONS(name, type) \
    list_##name* list_##name##_new(int capacity) { \
        list_##name *list = malloc(sizeof(list_##name)); \
        list->size = 0; \
        list->capacity = capacity; \
        list->data = malloc(list->capacity * sizeof(type)); \
        return list; \
    } \
    \
    void list_##name##_free(list_##name* list) { \
        free(list->data); \
        free(list); \
    } \
    void list_##name##_clear(list_##name* list) { \
        list->size = 0; \
    } \
    int list_##name##_insert(list_##name* list, size_t index, type value) { \
        if (list->size == list->capacity) { \
            list->capacity *= 2; \
            type* temp = list->data = realloc(list->data, list->capacity * sizeof(type)); \
            if (temp == NULL) { \
                return -1; \
            } \
        } \
        for (size_t i = list->size; i > index; i--) { \
            list->data[i] = list->data[i - 1]; \
        } \
        list->data[index] = value; \
        list->size++; \
        return 0; \
    } \
    void list_##name##_remove(list_##name* list, size_t index) { \
        if (index >= list->size) { \
            return; \
        } \
        for (size_t i = index; i < list->size - 1; i++) { \
            list->data[i] = list->data[i + 1]; \
        } \
        list->size--; \
    } \
    int list_##name##_push(list_##name* list, type value) { \
        if (list->size == list->capacity) { \
            list->capacity *= 2; \
            type* temp = realloc(list->data, list->capacity * sizeof(type)); \
            if (temp == NULL) { \
                return - 1; \
            } \
            list->data = temp; \
        } \
        list->data[list->size++] = value; \
        return 0; \
    } \
    void list_##name##_pop(list_##name* list) { \
        if (list->size > 0) { \
            list->size--; \
        } \
    }

DEFINE_LIST_FUNCTIONS(int, int)
DEFINE_LIST_FUNCTIONS(float, float)
DEFINE_LIST_FUNCTIONS(double, double)
DEFINE_LIST_FUNCTIONS(char, char)
DEFINE_LIST_FUNCTIONS(void_ptr, void*)