#include "src/list/list.h"

#include "CUnit/Basic.h"

void test_list_double_new(void) {
    int capacity = 10;
    list_double* list = list_double_new(capacity);
    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(list->capacity, capacity);
    list_double_free(list);
}

void test_list_double_clear(void) {
    list_double* list = list_double_new(10);
    list->size = 5;
    list_double_clear(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_double_free(list);
}

void test_list_double_insert(void) {
    list_double* list = list_double_new(10);
    list_double_insert(list, 0, 5.0);
    CU_ASSERT_EQUAL(list->data[0], 5.0);
    CU_ASSERT_EQUAL(list->size, 1);
    list_double_free(list);
}

void test_list_double_remove(void) {
    list_double* list = list_double_new(10);
    list_double_insert(list, 0, 5.0);
    list_double_remove(list, 0);
    CU_ASSERT_EQUAL(list->size, 0);
    list_double_free(list);
}

void test_list_double_push(void) {
    list_double* list = list_double_new(10);
    list_double_push(list, 5.0);
    CU_ASSERT_EQUAL(list->data[0], 5.0);
    CU_ASSERT_EQUAL(list->size, 1);
    list_double_free(list);
}

void test_list_double_pop(void) {
    list_double* list = list_double_new(10);
    list_double_push(list, 5.0);
    list_double_pop(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_double_free(list);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("list_double_suite", NULL, NULL);
    CU_add_test(suite, "test_list_double_new", test_list_double_new);
    CU_add_test(suite, "test_list_double_clear", test_list_double_clear);
    CU_add_test(suite, "test_list_double_insert", test_list_double_insert);
    CU_add_test(suite, "test_list_double_remove", test_list_double_remove);
    CU_add_test(suite, "test_list_double_push", test_list_double_push);
    CU_add_test(suite, "test_list_double_pop", test_list_double_pop);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}