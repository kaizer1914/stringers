#include "s21_string_tests.h"

START_TEST(strncpy_1) {
    char s1[100] = "If you really strain your ears, you can just about hear the sound of no one giving a damn.";
    char s2[100] = "If you really strain your ears, you can just about hear the sound of no one giving a damn.";
    char s3[] = "~!@#$^&*()_+|<>?`-=;',./";
    s21_size_t n = 13;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_2) {
    char s1[100] = "Lets all be unique together until we realise we are all the same.";
    char s2[100] = "Lets all be unique together until we realise we are all the same.";
    char s3[] = "\0";
    s21_size_t n = 1;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_3) {
    char s1[100] = "His thought process was on so many levels that he gave himself a phobia of heights.";
    char s2[100] = "His thought process was on so many levels that he gave himself a phobia of heights.";
    char s3[] = "touch";
    s21_size_t n = 1;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_4) {
    char s1[5] = "";
    char s2[5] = "";
    char s3[] = "";
    s21_size_t n = 0;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_5) {
    char s1[50] = "";
    char s2[50] = "";
    char s3[] = "!!!!!!!!!!!!!!!!!!!!!!!!!";
    s21_size_t n = strlen(s3);
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_6) {
    char s1[5] = "";
    char s2[5] = "";
    char s3[] = "\0";
    s21_size_t n = 1;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_7) {
    char s1[100] = "A kangaroo is really just a rabbit on steroids.";
    char s2[100] = "A kangaroo is really just a rabbit on steroids.";
    char s3[] = "People generally approve of dogs eating cat food but not cats eating dog food.";
    s21_size_t n = 30;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_8) {
    char s1[100] = "Tomatoes make great weapons when water balloons arent available.";
    char s2[100] = "Tomatoes make great weapons when water balloons arent available.";
    char s3[] = "Courage and stupidity were all he had.";
    s21_size_t n = 10;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_9) {
    char s1[100] = "She \nfound his \tcomplete dullness \0interesting.";
    char s2[100] = "She \nfound his \tcomplete dullness \0interesting.";
    char s3[] = "Siri \tbecame confused when we reused to follow her directions.";
    s21_size_t n = 20;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

START_TEST(strncpy_10) {
    char s1[100] = "Everyone was curious about the large white blimp that appeared overnight.";
    char s2[100] = "Everyone was curious about the large white blimp that appeared overnight.";
    char s3[] = "Everyone";
    s21_size_t n = 9;
    ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
} END_TEST

Suite *test_strncpy() {
    Suite *test_set = suite_create("s21_strncpy");
    TCase *test_group = tcase_create("strncpy_test_group");

    tcase_add_test(test_group, strncpy_1);
    tcase_add_test(test_group, strncpy_2);
    tcase_add_test(test_group, strncpy_3);
    tcase_add_test(test_group, strncpy_4);
    tcase_add_test(test_group, strncpy_5);
    tcase_add_test(test_group, strncpy_6);
    tcase_add_test(test_group, strncpy_7);
    tcase_add_test(test_group, strncpy_8);
    tcase_add_test(test_group, strncpy_9);
    tcase_add_test(test_group, strncpy_10);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
