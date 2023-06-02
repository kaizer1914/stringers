#include "s21_string_tests.h"

START_TEST(strpbrk_1) {
  char s1[] = "Imagine his surprise when he discovered that the safe was full of pudding.";
  char s2[] = "Imagine his surprise when he discovered that the safe was full of pudding.";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "AwD";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "634817676681876316831";
  char s2[] = "716867167133";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_7) {
  char s1[] = "adadadad";
  char s2[] = "wqwqqwwq";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_8) {
  char s1[] = "wqwqwqwq";
  char s2[] = "awddwawdq";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_9) {
  char s1[] = "Always bring cinnamon buns on a deep-sea diving expedition.";
  char s2[] = "She couldnt understand why nobody else could see that the sky is full of cotton candy.";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_10) {
  char s1[] = "He waited for the stop sign to turn to a go sign.";
  char s2[] = "She did not cheat on the test, for it was not the right thing to do.";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

START_TEST(strpbrk_11) {
  char s1[] = "Smoky\t\n\b\0 the Bear secretly started the fires.";
  char s2[] = "He\t\n\b\0 found his art never progressed when he literally used his sweat and tears.";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
} END_TEST

Suite *test_strpbrk() {
    Suite *test_set = suite_create("s21_strpbrk");
    TCase *test_group = tcase_create("strpbrk_test_group");

    tcase_add_test(test_group, strpbrk_1);
    tcase_add_test(test_group, strpbrk_2);
    tcase_add_test(test_group, strpbrk_3);
    tcase_add_test(test_group, strpbrk_4);
    tcase_add_test(test_group, strpbrk_5);
    tcase_add_test(test_group, strpbrk_6);
    tcase_add_test(test_group, strpbrk_7);
    tcase_add_test(test_group, strpbrk_8);
    tcase_add_test(test_group, strpbrk_9);
    tcase_add_test(test_group, strpbrk_10);
    tcase_add_test(test_group, strpbrk_11);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
