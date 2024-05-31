#include "CUnit/Basic.h"
#include "src/string/cstring.h"

void test_string_new_empty(void) {
    string s = string_new_empty();
    CU_ASSERT_PTR_NOT_NULL(s.data);
    CU_ASSERT_EQUAL(s.length, 0);
    string_free(&s);
}

void test_string_new_char(void) {
    string s = string_new("test");
    CU_ASSERT_STRING_EQUAL(s.data, "test");
    CU_ASSERT_EQUAL(s.length, 4);
    string_free(&s);
}

void test_string_free(void) {
    string s = string_new("test");
    string_free(&s);
    CU_ASSERT_PTR_NULL(s.data);
    CU_ASSERT_EQUAL(s.length, 0);
}

void test_string_concat_string(void) {
    string s1 = string_new("Hello");
    string s2 = string_new(" World");
    string_concat_string(&s1, &s2);
    CU_ASSERT_STRING_EQUAL(s1.data, "Hello World");
    CU_ASSERT_EQUAL(s1.length, 11);
    string_free(&s1);
    string_free(&s2);
}

void test_string_concat_char(void) {
    string s = string_new("Hello");
    string_concat_char(&s, '!');
    CU_ASSERT_STRING_EQUAL(s.data, "Hello!");
    CU_ASSERT_EQUAL(s.length, 6);
    string_free(&s);
}

void test_string_find_string(void) {
    string s = string_new("Hello World");
    string sub = string_new("World");
    int pos = string_find_string(&s, &sub);
    CU_ASSERT_EQUAL(pos, 6);
    string_free(&s);
    string_free(&sub);
}

void test_string_find_char(void) {
    string s = string_new("Hello World");
    int pos = string_find_char(&s, 'W');
    CU_ASSERT_EQUAL(pos, 6);
    string_free(&s);
}

void test_string_substring(void) {
    string s = string_new("Hello World");
    string sub = string_substring(&s, 0, 5);
    CU_ASSERT_STRING_EQUAL(sub.data, "Hello");
    CU_ASSERT_EQUAL(sub.length, 5);
    string_free(&s);
    string_free(&sub);
}

void test_string_compare_string(void) {
    string s1 = string_new("Hello");
    string s2 = string_new("World");
    int cmp = string_compare_string(&s1, &s2);
    CU_ASSERT(cmp < 0);
    string_free(&s1);
    string_free(&s2);
}

void test_string_compare_char(void) {
    string s = string_new("Hello");
    int cmp = string_compare_char(&s, "World");
    CU_ASSERT(cmp < 0);
    string_free(&s);
}

void test_string_remove(void) {
    string s = string_new("Hello World");
    string_remove(&s, 0, 6);
    CU_ASSERT_STRING_EQUAL(s.data, "World");
    CU_ASSERT_EQUAL(s.length, 5);
    string_free(&s);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("string_test", 0, 0);

    CU_add_test(suite, "test_string_new_empty", test_string_new_empty);
    CU_add_test(suite, "test_string_new_char", test_string_new_char);
    CU_add_test(suite, "test_string_free", test_string_free);
    CU_add_test(suite, "test_string_concat_string", test_string_concat_string);
    CU_add_test(suite, "test_string_concat_char", test_string_concat_char);
    CU_add_test(suite, "test_string_find_string", test_string_find_string);
    CU_add_test(suite, "test_string_find_char", test_string_find_char);
    CU_add_test(suite, "test_string_substring", test_string_substring);
    CU_add_test(suite, "test_string_compare_string", test_string_compare_string);
    CU_add_test(suite, "test_string_compare_char", test_string_compare_char);
    CU_add_test(suite, "test_string_remove", test_string_remove);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}