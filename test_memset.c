#include "s21_string_tests.h"

START_TEST(memset_1) {
    char s1[] = "Dan took the deep dive down the rabbit hole.";
    char s2[] = "Dan took the deep dive down the rabbit hole.";
    int ch = ' ';
    s21_size_t n = 8;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_2) {
    char s1[] = "If my calculator had a history, it would be more embarrassing than my browser history.";
    char s2[] = "If my calculator had a history, it would be more embarrassing than my browser history.";
    int ch = 'Z';
    s21_size_t n = 5;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_3) {
    char s1[] = "The door swung open to reveal pink giraffes and red elephants.";
    char s2[] = "The door swung open to reveal pink giraffes and red elephants.";
    int ch = 'q';
    s21_size_t n = 0;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_4) {
    char s1[] = "Excitement replaced fear until the final moment.";
    char s2[] = "Excitement replaced fear until the final moment.";
    int ch = '\0';
    s21_size_t n = 1;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_5) {
    char s1[] = "Her daily goal was to improve on yesterday.";
    char s2[] = "Her daily goal was to improve on yesterday.";
    int ch = '\0';
    s21_size_t n = 4;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_6) {
    char s1[] = "Various sea birds are elegant, but nothing is as elegant as a gliding pelican.";
    char s2[] = "Various sea birds are elegant, but nothing is as elegant as a gliding pelican.";
    int ch = '\t';
    s21_size_t n = 8;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_7) {
    char s1[] = "The sun\t had set\n and so\0 had his dreams.";
    char s2[] = "The sun\t had set\n and so\0 had his dreams.";
    int ch = '\b';
    s21_size_t n = 8;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_8) {
    char s1[] = "Az\tQg\n\0CjK";
    char s2[] = "Az\tQg\n\0CjK";
    int ch = 'P';
    s21_size_t n = 5;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_9) {
    char s1[] = "He put heat on the wound to see what would grow.";
    char s2[] = "He put heat on the wound to see what would grow.";
    int ch = 'H';
    s21_size_t n = 2;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

START_TEST(memset_10) {
    char s1[] = "     ";
    char s2[] = "     ";
    int ch = 'S';
    s21_size_t n = 3;
    ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
} END_TEST

Suite *test_memset() {
    Suite *test_set = suite_create("s21_memset");
    TCase *test_group = tcase_create("memset_test_group");

    tcase_add_test(test_group, memset_1);
    tcase_add_test(test_group, memset_2);
    tcase_add_test(test_group, memset_3);
    tcase_add_test(test_group, memset_4);
    tcase_add_test(test_group, memset_5);
    tcase_add_test(test_group, memset_6);
    tcase_add_test(test_group, memset_7);
    tcase_add_test(test_group, memset_8);
    tcase_add_test(test_group, memset_9);
    tcase_add_test(test_group, memset_10);

    suite_add_tcase(test_set, test_group);
    return test_set;
}
