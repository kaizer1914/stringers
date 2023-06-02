#include "s21_string_tests.h"

START_TEST(to_upper_1) {
    char s1[] = "hello, world!";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "HELLO, WORLD!");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_2) {
    char s1[] = "ALREADY UPPER";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "ALREADY UPPER");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_3) {
    char s1[] = "";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_4) {
    char s1[] = "HaLf LiFe 123456789";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "HALF LIFE 123456789");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_5) {
    char s1[] = "\n1234g56789\t";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "\n1234G56789\t");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_6) {
    char *s1 = s21_NULL;
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, s21_NULL);
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_7) {
    char *s1 = "~!@#$^&*()_+-school21=`;',./<>?:|";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "~!@#$^&*()_+-SCHOOL21=`;',./<>?:|");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_8) {
    char s1[] = "London is the capital of Great Britain";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "LONDON IS THE CAPITAL OF GREAT BRITAIN");
    if (s2) free(s2);
} END_TEST

START_TEST(to_upper_9) {
    char s1[] = "How\n can\t I\0 help?";
    char *s2 = s21_to_upper(s1);
    ck_assert_pstr_eq(s2, "HOW\n CAN\t I\0 HELP?");
    if (s2) free(s2);
} END_TEST

Suite *test_to_upper() {
    Suite *test_set = suite_create("s21_to_upper");
    TCase *test_group = tcase_create("to_upper_test_group");

    tcase_add_test(test_group, to_upper_1);
    tcase_add_test(test_group, to_upper_2);
    tcase_add_test(test_group, to_upper_3);
    tcase_add_test(test_group, to_upper_4);
    tcase_add_test(test_group, to_upper_5);
    tcase_add_test(test_group, to_upper_6);
    tcase_add_test(test_group, to_upper_7);
    tcase_add_test(test_group, to_upper_8);
    tcase_add_test(test_group, to_upper_9);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
