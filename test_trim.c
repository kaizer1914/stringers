#include "s21_string_tests.h"

START_TEST(trim_1) {
    char s1[] = "Shakespeare was a famous 17th-century diesel mechanic";
    char s2[] = "Shakespeare mechanic";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "was a famous 17th-century diesel");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_2) {
    char s1[] = "It was the first time he had ever seen someone cook dinner on an elephant";
    char s2[] = "It was";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "he first time he had ever seen someone cook dinner on an elephan");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_3) {
    char s1[] = "She learned that water bottles are no longer just to hold liquid";
    char s2[] = "She learned liquid";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "that water bottles are no longer just to ho");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_4) {
    char s1[] = "";
    char s2[] = "";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, s21_NULL);
    if (s3) free(s3);
} END_TEST

START_TEST(trim_5) {
    char s1[] = " ";
    char s2[] = " ";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, s21_NULL);
    if (s3) free(s3);
} END_TEST

START_TEST(trim_6) {
    char s1[] = "test";
    char s2[] = "test";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, s21_NULL);
    if (s3) free(s3);
} END_TEST

START_TEST(trim_7) {
    char s1[] = "Had he known what was going to happen";
    char s2[] = "going";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "Had he known what was going to happe");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_8) {
    char s1[] = "Everyone says they love nature until they realize how dangerous she can be...";
    char s2[] = "... ";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "Everyone says they love nature until they realize how dangerous she can be");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_9) {
    char s1[] = "obligation";
    char s2[] = "onb";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "ligati");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_10) {
    char s1[] = " free(!s1)";
    char s2[] = "!s1() ";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "free");
    if (s3) free(s3);
} END_TEST

START_TEST(trim_11) {
    char s1[] = "spokesperson";
    char s2[] = "spon";
    char *s3 = s21_trim(s1, s2);
    ck_assert_pstr_eq(s3, "kesper");
    if (s3) free(s3);
} END_TEST

Suite *test_trim() {
    Suite *test_set = suite_create("s21_trim");
    TCase *test_group = tcase_create("trim_test_group");

    tcase_add_test(test_group, trim_1);
    tcase_add_test(test_group, trim_2);
    tcase_add_test(test_group, trim_3);
    tcase_add_test(test_group, trim_4);
    tcase_add_test(test_group, trim_5);
    tcase_add_test(test_group, trim_6);
    tcase_add_test(test_group, trim_7);
    tcase_add_test(test_group, trim_8);
    tcase_add_test(test_group, trim_9);
    tcase_add_test(test_group, trim_10);
    tcase_add_test(test_group, trim_11);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
