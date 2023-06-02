#include "s21_string_tests.h"

START_TEST(strrchr_1) {
    char s[] = "I want more detailed information.";
    int ch = 'I';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_2) {
    char s[] = "This book is sure to liquefy your brain.";
    int ch = '\0';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_3) {
    char s[] = "This is a Japanese doll.";
    int ch = '.';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_4) {
    char s[] = "The tortoise jumped into the lake with dreams of becoming a sea turtle.";
    int ch = ' ';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_5) {
    char s[] = "175427812547890!~!@#$^&*()_+-=;'|,./<>?`";
    int ch = '0';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_6) {
    char s[] = "The delicious aroma from the kitchen was ruined by cigarette smoke.";
    int ch = 'f';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_7) {
    char s[] = "ssssssssssssssss";
    int ch = 's';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_8) {
    char s[] = "Mars";
    int ch = 'q';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_9) {
    char s[] = "I hear\0 that\t \nNancy is\n very\0 pretty.";
    int ch = '\n';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

START_TEST(strrchr_10) {
    char s[] = "While \0on the \tfirst date he \naccidentally\t\n hit his head on the beam.";
    int ch = '\t';
    ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
} END_TEST

Suite *test_strrchr() {
    Suite *test_set = suite_create("s21_strrchr");
    TCase *test_group = tcase_create("strrchr_test_group");

    tcase_add_test(test_group, strrchr_1);
    tcase_add_test(test_group, strrchr_2);
    tcase_add_test(test_group, strrchr_3);
    tcase_add_test(test_group, strrchr_4);
    tcase_add_test(test_group, strrchr_5);
    tcase_add_test(test_group, strrchr_6);
    tcase_add_test(test_group, strrchr_7);
    tcase_add_test(test_group, strrchr_8);
    tcase_add_test(test_group, strrchr_9);
    tcase_add_test(test_group, strrchr_10);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
