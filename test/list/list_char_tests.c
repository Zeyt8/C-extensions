#include "src/list/list.h"

#include "CUnit/Basic.h"

void test_list_char_new(void) {
    int capacity = 10;
    list_char* list = list_char_new(capacity);
    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(list->capacity, capacity);
    list_char_free(list);
}

void test_list_char_clear(void) {
    list_char* list = list_char_new(10);
    list->size = 5;
    list_char_clear(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_char_free(list);
}

void test_list_char_insert(void) {
    list_char* list = list_char_new(10);
    list_char_insert(list, 0, 'a');
    CU_ASSERT_EQUAL(list->data[0], 'a');
    CU_ASSERT_EQUAL(list->size, 1);
    list_char_free(list);
}

void test_list_char_remove(void) {
    list_char* list = list_char_new(10);
    list_char_insert(list, 0, 'a');
    list_char_remove(list, 0);
    CU_ASSERT_EQUAL(list->size, 0);
    list_char_free(list);
}

void test_list_char_push(void) {
    list_char* list = list_char_new(10);
    list_char_push(list, 'a');
    CU_ASSERT_EQUAL(list->data[0], 'a');
    CU_ASSERT_EQUAL(list->size, 1);
    list_char_free(list);
}

void test_list_char_pop(void) {
    list_char* list = list_char_new(10);
    list_char_push(list, 'a');
    list_char_pop(list);
    CU_ASSERT_EQUAL(list->size, 0);
    list_char_free(list);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("list_char", NULL, NULL);
    CU_add_test(suite, "test_list_char_new", test_list_char_new);
    CU_add_test(suite, "test_list_char_clear", test_list_char_clear);
    CU_add_test(suite, "test_list_char_insert", test_list_char_insert);
    CU_add_test(suite, "test_list_char_remove", test_list_char_remove);
    CU_add_test(suite, "test_list_char_push", test_list_char_push);
    CU_add_test(suite, "test_list_char_pop", test_list_char_pop);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}