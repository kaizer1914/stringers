#include "s21_string_tests.h"

START_TEST(to_lower_1) {
    char s1[] = "HELLO, WORLD!";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "hello, world!");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_2) {
    char s1[] = "already lower";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "already lower");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_3) {
    char s1[] = "";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_4) {
    char s1[] = "HaLf LiFe 123456789";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "half life 123456789");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_5) {
    char s1[] = "\n1234G56789\t";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "\n1234g56789\t");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_6) {
    char *s1 = s21_NULL;
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, s21_NULL);
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_7) {
    char *s1 = "~!@#$^&*()_+-SCHOOL21=`;',./<>?:|";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "~!@#$^&*()_+-school21=`;',./<>?:|");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_8) {
    char s1[] = "London is the capital of Great Britain";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "london is the capital of great britain");
    if (s2) free(s2);
} END_TEST

START_TEST(to_lower_9) {
    char s1[] = "How\n can\t I\0 help?";
    char *s2 = s21_to_lower(s1);
    ck_assert_pstr_eq(s2, "how\n can\t i\0 help?");
    if (s2) free(s2);
} END_TEST

Suite *test_to_lower() {
    Suite *test_set = suite_create("s21_to_lower");
    TCase *test_group = tcase_create("to_lower_test_group");

    tcase_add_test(test_group, to_lower_1);
    tcase_add_test(test_group, to_lower_2);
    tcase_add_test(test_group, to_lower_3);
    tcase_add_test(test_group, to_lower_4);
    tcase_add_test(test_group, to_lower_5);
    tcase_add_test(test_group, to_lower_6);
    tcase_add_test(test_group, to_lower_7);
    tcase_add_test(test_group, to_lower_8);
    tcase_add_test(test_group, to_lower_9);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
