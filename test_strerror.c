#include "s21_string_tests.h"

START_TEST(strerror_1) {
    int n = 0;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_2) {
    int n = 10;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_3) {
    int n = 40;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_4) {
    int n = 60;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_5) {
    int n = 70;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_6) {
    int n = 100;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_7) {
    int n = 125;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_8) {
    int n = 17;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_9) {
    int n = 28;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_10) {
    int n = 32;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_11) {
    int n = 44;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_12) {
    int n = 72;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_13) {
    int n = 84;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_14) {
    int n = 98;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_15) {
    int n = 117;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

START_TEST(strerror_16) {
    int n = 20;
    ck_assert_str_eq(strerror(n), s21_strerror(n));
} END_TEST

Suite *test_strerror() {
    Suite *test_set = suite_create("s21_strerror");
    TCase *test_group = tcase_create("strerror_test_group");

    tcase_add_test(test_group, strerror_1);
    tcase_add_test(test_group, strerror_2);
    tcase_add_test(test_group, strerror_3);
    tcase_add_test(test_group, strerror_4);
    tcase_add_test(test_group, strerror_5);
    tcase_add_test(test_group, strerror_6);
    tcase_add_test(test_group, strerror_7);
    tcase_add_test(test_group, strerror_8);
    tcase_add_test(test_group, strerror_9);
    tcase_add_test(test_group, strerror_10);
    tcase_add_test(test_group, strerror_11);
    tcase_add_test(test_group, strerror_12);
    tcase_add_test(test_group, strerror_13);
    tcase_add_test(test_group, strerror_14);
    tcase_add_test(test_group, strerror_15);
    tcase_add_test(test_group, strerror_16);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
