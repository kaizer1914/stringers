#include "s21_string_tests.h"

START_TEST(memcpy_1) {
    char s1[] = "his seven-layer cake only had six layers.";
    char s2[] = "his seven-layer cake only had six layers.";
    char s3[] = "The chic gangster liked to start the day with a pink scarf.";
    s21_size_t n = 15;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_2) {
    char s1[] = "She always speaks to him in a loud voice.";
    char s2[] = "She always speaks to him in a loud voice.";
    char s3[] = "\0";
    s21_size_t n = 1;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_3) {
    char s1[] = "The tears of a clown make my lipstick run, but my shower cap is still intact.";
    char s2[] = "The tears of a clown make my lipstick run, but my shower cap is still intact.";
    char s3[] = "";
    s21_size_t n = 0;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_4) {
    char s1[] = "";
    char s2[] = "";
    char s3[] = "Charles ate the french fries knowing they would be his last meal.";
    s21_size_t n = 0;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_5) {
    char s1[] = "The overpass went under the highway and into a secret world.";
    char s2[] = "The overpass went under the highway and into a secret world.";
    char s3[] = "The beach was crowded with snow leopards.";
    s21_size_t n = 3;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_6) {
    char s1[] = "With a single flip of the coin, his life changed forever.";
    char s2[] = "With a single flip of the coin, his life changed forever.";
    char s3[] = "With a single flip of the coin, his life changed forever.";
    s21_size_t n = strlen(s3);
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_7) {
    char s1[] = "Today I dressed my unicorn in preparation for the race.";
    char s2[] = "Today I dressed my unicorn in preparation for the race.";
    char s3[] = "She\0 wore\n green\t lipstick\0 like a fashion icon.";
    s21_size_t n = 20;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_8) {
    char s1[] = "Karen\t realized\0 the\n only\t way she was\0 getting into\t heaven was to\n cheat.";
    char s2[] = "Karen\t realized\0 the\n only\t way she was\0 getting into\t heaven was to\n cheat.";
    char s3[] = "Jenny \0made \tthe \nannouncement \0that her baby was an alien.";
    s21_size_t n = 25;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

START_TEST(memcpy_9) {
    char s1[] = "\0\t\n\b\0\t\n";
    char s2[] = "\0\t\n\b\0\t\n";
    char s3[] = "\t\n\0\b\t";
    s21_size_t n = 5;
    ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
} END_TEST

Suite *test_memcpy() {
    Suite *test_set = suite_create("s21_memcpy");
    TCase *test_group = tcase_create("memcpy_test_group");

    tcase_add_test(test_group, memcpy_1);
    tcase_add_test(test_group, memcpy_2);
    tcase_add_test(test_group, memcpy_3);
    tcase_add_test(test_group, memcpy_4);
    tcase_add_test(test_group, memcpy_5);
    tcase_add_test(test_group, memcpy_6);
    tcase_add_test(test_group, memcpy_7);
    tcase_add_test(test_group, memcpy_8);
    tcase_add_test(test_group, memcpy_9);

    suite_add_tcase(test_set, test_group);
    return test_set;
}
