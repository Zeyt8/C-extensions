#include "src/list/list.h"

#include "CUnit/Basic.h"

void test_list_void_ptr_new(void) {
    int capacity = 10;
    list_void_ptr* list = list_void_ptr_new(capacity);
    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(list->capacity, capacity);
    list_void_ptr_free(list);
}

void test_list_void_ptr_clear(void) {
    list_void_ptr* list = list_void_ptr_new(10);
    list->size = 5;
    list_void_ptr_clear(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_void_ptr_free(list);
}

void test_list_void_ptr_insert(void) {
    list_void_ptr* list = list_void_ptr_new(10);
    int value = 5;
    list_void_ptr_insert(list, 0, &value);
    CU_ASSERT_PTR_EQUAL(list->data[0], &value);
    CU_ASSERT_EQUAL(list->size, 1);
    list_void_ptr_free(list);
}

void test_list_void_ptr_remove(void) {
    list_void_ptr* list = list_void_ptr_new(10);
    int value = 5;
    list_void_ptr_insert(list, 0, &value);
    list_void_ptr_remove(list, 0);
    CU_ASSERT_EQUAL(list->size, 0);
    list_void_ptr_free(list);
}

void test_list_void_ptr_push(void) {
    list_void_ptr* list = list_void_ptr_new(10);
    int value = 5;
    list_void_ptr_push(list, &value);
    CU_ASSERT_PTR_EQUAL(list->data[0], &value);
    CU_ASSERT_EQUAL(list->size, 1);
    list_void_ptr_free(list);
}

void test_list_void_ptr_pop(void) {
    list_void_ptr* list = list_void_ptr_new(10);
    int value = 5;
    list_void_ptr_push(list, &value);
    list_void_ptr_pop(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_void_ptr_free(list);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("list_test", 0, 0);

    CU_add_test(suite, "test_list_void_ptr_new", test_list_void_ptr_new);
    CU_add_test(suite, "test_list_void_ptr_clear", test_list_void_ptr_clear);
    CU_add_test(suite, "test_list_void_ptr_insert", test_list_void_ptr_insert);
    CU_add_test(suite, "test_list_void_ptr_remove", test_list_void_ptr_remove);
    CU_add_test(suite, "test_list_void_ptr_push", test_list_void_ptr_push);
    CU_add_test(suite, "test_list_void_ptr_pop", test_list_void_ptr_pop);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}