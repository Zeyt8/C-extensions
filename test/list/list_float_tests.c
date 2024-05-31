#include "src/list/list.h"

#include "CUnit/Basic.h"

void test_list_float_new(void) {
    int capacity = 10;
    list_float* list = list_float_new(capacity);
    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(list->capacity, capacity);
    list_float_free(list);
}

void test_list_float_clear(void) {
    list_float* list = list_float_new(10);
    list->size = 5;
    list_float_clear(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_float_free(list);
}

void test_list_float_insert(void) {
    list_float* list = list_float_new(10);
    list_float_insert(list, 0, 5.0f);
    CU_ASSERT_EQUAL(list->data[0], 5.0f);
    CU_ASSERT_EQUAL(list->size, 1);
    list_float_free(list);
}

void test_list_float_remove(void) {
    list_float* list = list_float_new(10);
    list_float_insert(list, 0, 5.0f);
    list_float_remove(list, 0);
    CU_ASSERT_EQUAL(list->size, 0);
    list_float_free(list);
}

void test_list_float_push(void) {
    list_float* list = list_float_new(10);
    list_float_push(list, 5.0f);
    CU_ASSERT_EQUAL(list->data[0], 5.0f);
    CU_ASSERT_EQUAL(list->size, 1);
    list_float_free(list);
}

void test_list_float_pop(void) {
    list_float* list = list_float_new(10);
    list_float_push(list, 5.0f);
    list_float_pop(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_float_free(list);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("list_float", NULL, NULL);
    CU_add_test(suite, "test_list_float_new", test_list_float_new);
    CU_add_test(suite, "test_list_float_clear", test_list_float_clear);
    CU_add_test(suite, "test_list_float_insert", test_list_float_insert);
    CU_add_test(suite, "test_list_float_remove", test_list_float_remove);
    CU_add_test(suite, "test_list_float_push", test_list_float_push);
    CU_add_test(suite, "test_list_float_pop", test_list_float_pop);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}