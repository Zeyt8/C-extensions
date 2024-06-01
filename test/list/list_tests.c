#include <CUnit/Basic.h>
#include "src/list/list.h"
#include "src/list/list_extensions.h"

void test_list_new() {
    list* l = list_new(10, sizeof(int));
    CU_ASSERT_EQUAL(l->size, 0);
    CU_ASSERT_EQUAL(l->capacity, 10);
    CU_ASSERT_EQUAL(l->element_size, sizeof(int));
    list_free(l);
}

void test_list_new_ptr() {
    list* l = list_new(10, sizeof(int*));
    CU_ASSERT_EQUAL(l->size, 0);
    CU_ASSERT_EQUAL(l->capacity, 10);
    CU_ASSERT_EQUAL(l->element_size, sizeof(int*));
    list_free(l);
}

void test_list_free() {
    list* l = list_new(10, sizeof(int));
    list_free(l);
    CU_ASSERT(1 == 1);
}

void test_list_free_ptr() {
    list* l = list_new(10, sizeof(int*));
    list_free(l);
    CU_ASSERT(1 == 1);
}

void test_list_clear() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_insert(l, 0, &value);
    list_clear(l);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_clear_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_insert(l, 0, &ptr);
    list_clear(l);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_get_set() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_set(l, 0, value);
    int result = list_get(int, l, 0);
    CU_ASSERT_EQUAL(result, value);
    list_free(l);
}

void test_list_get_set_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_set(l, 0, ptr);
    int* result = list_get(int*, l, 0);
    CU_ASSERT_PTR_EQUAL(result, ptr);
    list_free(l);
}

void test_list_insert() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_insert(l, 0, &value);
    int result = list_get(int, l, 0);
    CU_ASSERT_EQUAL(result, value);
    list_free(l);
}

void test_list_insert_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_insert(l, 0, &ptr);
    int* result = list_get(int*, l, 0);
    CU_ASSERT_PTR_EQUAL(result, ptr);
    list_free(l);
}

void test_list_remove() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_insert(l, 0, &value);
    list_remove(l, 0);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_remove_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_insert(l, 0, &ptr);
    list_remove(l, 0);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_push() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_push(l, &value);
    int result = list_get(int, l, 0);
    CU_ASSERT_EQUAL(result, value);
    list_free(l);
}

void test_list_push_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_push(l, &ptr);
    int* result = list_get(int*, l, 0);
    CU_ASSERT_PTR_EQUAL(result, ptr);
    list_free(l);
}

void test_list_pop() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_push(l, &value);
    list_pop(l);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_pop_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_push(l, &ptr);
    list_pop(l);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_remove_optimized() {
    list* l = list_new(10, sizeof(int));
    int value = 5;
    list_push(l, &value);
    list_remove_optimized(l, 0);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

void test_list_remove_optimized_ptr() {
    list* l = list_new(10, sizeof(int*));
    int value = 5;
    int* ptr = &value;
    list_push(l, &ptr);
    list_remove_optimized(l, 0);
    CU_ASSERT_EQUAL(l->size, 0);
    list_free(l);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("list", NULL, NULL);

    CU_add_test(suite, "new", test_list_new);
    CU_add_test(suite, "new_ptr", test_list_new_ptr);
    CU_add_test(suite, "free", test_list_free);
    CU_add_test(suite, "free", test_list_free_ptr);
    CU_add_test(suite, "clear", test_list_clear);
    CU_add_test(suite, "clear_ptr", test_list_clear_ptr);
    CU_add_test(suite, "get_set", test_list_get_set);
    CU_add_test(suite, "get_set_ptr", test_list_get_set_ptr);
    CU_add_test(suite, "insert", test_list_insert);
    CU_add_test(suite, "insert_ptr", test_list_insert_ptr);
    CU_add_test(suite, "remove", test_list_remove);
    CU_add_test(suite, "remove_ptr", test_list_remove_ptr);

    suite = CU_add_suite("list_extensions", NULL, NULL);

    CU_add_test(suite, "push", test_list_push);
    CU_add_test(suite, "push_ptr", test_list_push_ptr);
    CU_add_test(suite, "pop", test_list_pop);
    CU_add_test(suite, "pop_ptr", test_list_pop_ptr);
    CU_add_test(suite, "remove_optimized", test_list_remove_optimized);
    CU_add_test(suite, "remove_optimized_ptr", test_list_remove_optimized_ptr);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}