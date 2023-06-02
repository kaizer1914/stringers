#include "s21_string_tests.h"

START_TEST(strchr_1) {
    char s[] = "Sometimes you have to just give up and win by cheating.";
    int ch = 'S';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_2) {
    char s[] = "Peter found road kill an excellent way to save money on dinner.";
    int ch = '\0';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_3) {
    char s[] = "When he encountered maize for the first time, he thought it incredibly corny.";
    int ch = ' ';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_4) {
    char s[] = "The quick brown fox jumps over the lazy dog.";
    int ch = '.';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_5) {
    char s[] = "~!@#$^&*()_+:|<>?`-=;'|<>?/";
    int ch = ';';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_6) {
    char s[] = "Blue sounded too \tcold at\t the time and yet it\n seemed to work for\0 gin.";
    int ch = '\t';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_7) {
    char s[] = "444444444444";
    int ch = '4';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_8) {
    char s[] = "She had \tthat \0tint of craziness in her soul that made \0her believe she \ncould \0actually make a difference.";
    int ch = '\0';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_9) {
    char s[] = "Truth in advertising and dinosaurs with skateboards have much in common.";
    int ch = 'a';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

START_TEST(strchr_10) {
    char s[] = "Nobody loves a pig wearing lipstick.";
    int ch = 'Q';
    ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
} END_TEST

Suite *test_strchr() {
    Suite *test_set = suite_create("s21_strchr");
    TCase *test_group = tcase_create("strchr_test_group");

    tcase_add_test(test_group, strchr_1);
    tcase_add_test(test_group, strchr_2);
    tcase_add_test(test_group, strchr_3);
    tcase_add_test(test_group, strchr_4);
    tcase_add_test(test_group, strchr_5);
    tcase_add_test(test_group, strchr_6);
    tcase_add_test(test_group, strchr_7);
    tcase_add_test(test_group, strchr_8);
    tcase_add_test(test_group, strchr_9);
    tcase_add_test(test_group, strchr_10);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
