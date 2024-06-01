#pragma once

#include "list.h"

#define PUSH_ERROR -1

int list_push(list* list, void* value);
void list_pop(list* list);
void list_remove_optimized(list* list, size_t index);