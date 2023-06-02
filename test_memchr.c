#include "s21_string_tests.h"

START_TEST(memchr_1) {
    char str[] = "This made him feel like an old-style rootbeer float smells.";
    int ch = ' ';
    s21_size_t len = strlen(str);
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_2) {
    char str[] = "Mom didn’t understand why no one else wanted a hot tub full of jello.";
    int ch = '1';
    s21_size_t len = strlen(str);
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_3) {
    char str[] = "Grape jelly was leaking out the hole in the roof.";
    int ch = 'l';
    s21_size_t len = 10;
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_4) {
    char str[] = "Hello, world!";
    int ch = '\0';
    s21_size_t len = 10;
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_5) {
    char str[] = "Being unacquainted with the chief raccoon was harming his prospects for promotion.";
    int ch = '\0';
    s21_size_t len = 3;
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_6) {
    char str[] = "";
    int ch = '7';
    s21_size_t len = 1;
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_7) {
    char str[] = "\0\t\b\n";
    int ch = '\n';
    s21_size_t len = 1;
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

START_TEST(memchr_8) {
    char str[] = "\0\t\b\n\0";
    int ch = ' ';
    s21_size_t len = 3;
    ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
} END_TEST

Suite *test_memchr() {
    Suite *test_set = suite_create("s21_memchr");
    TCase *test_group = tcase_create("memchr_test_group");

    tcase_add_test(test_group, memchr_1);
    tcase_add_test(test_group, memchr_2);
    tcase_add_test(test_group, memchr_3);
    tcase_add_test(test_group, memchr_4);
    tcase_add_test(test_group, memchr_5);
    tcase_add_test(test_group, memchr_6);
    tcase_add_test(test_group, memchr_7);
    tcase_add_test(test_group, memchr_8);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
