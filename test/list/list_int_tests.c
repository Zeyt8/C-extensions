#include "src/list/list.h"

#include "CUnit/Basic.h"

void test_list_int_new(void) {
    int capacity = 10;
    list_int* list = list_int_new(capacity);
    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(list->capacity, capacity);
    list_int_free(list);
}

void test_list_int_clear(void) {
    list_int* list = list_int_new(10);
    list->size = 5;
    list_int_clear(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_int_free(list);
}

void test_list_int_insert(void) {
    list_int* list = list_int_new(10);
    list_int_insert(list, 0, 5);
    CU_ASSERT_EQUAL(list->data[0], 5);
    CU_ASSERT_EQUAL(list->size, 1);
    list_int_free(list);
}

void test_list_int_remove(void) {
    list_int* list = list_int_new(10);
    list_int_insert(list, 0, 5);
    list_int_remove(list, 0);
    CU_ASSERT_EQUAL(list->size, 0);
    list_int_free(list);
}

void test_list_int_push(void) {
    list_int* list = list_int_new(10);
    list_int_push(list, 5);
    CU_ASSERT_EQUAL(list->data[0], 5);
    CU_ASSERT_EQUAL(list->size, 1);
    list_int_free(list);
}

void test_list_int_pop(void) {
    list_int* list = list_int_new(10);
    list_int_push(list, 5);
    list_int_pop(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_int_free(list);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("list_test", 0, 0);

    CU_add_test(suite, "test_list_int_new", test_list_int_new);
    CU_add_test(suite, "test_list_int_clear", test_list_int_clear);
    CU_add_test(suite, "test_list_int_insert", test_list_int_insert);
    CU_add_test(suite, "test_list_int_remove", test_list_int_remove);
    CU_add_test(suite, "test_list_int_push", test_list_int_push);
    CU_add_test(suite, "test_list_int_pop", test_list_int_pop);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}