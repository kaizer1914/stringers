#include "s21_string_tests.h"

START_TEST(strstr_1) {
    char s1[] = "Im working on a sweet potato farm.";
    char s2[] = "Im working on a sweet potato farm.";
    ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_2) {
  char s1[] = "At that moment she realized she had a sixth sense.";
  char s2[] = "she";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_3) {
  char s1[] = "Mary realized if her calculator had a history, it would be more embarrassing than her computer browser history";
  char s2[] = ",";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_4) {
  char s1[] = "When nobody is around, the trees gossip about the people who have walked under them.";
  char s2[] = "s";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_6) {
  char s1[] = "Tomorrow will bring something new, so leave today as a memory.";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_7) {
  char s1[] = "";
  char s2[] = "Trash covered the landscape like sprinkles do a birthday cake.";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_8) {
  char s1[] = "The crowd yells and screams for more memes.";
  char s2[] = ".";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_9) {
  char s1[] = "The knives were out and she was sharpening hers.";
  char s2[] = "were out and ";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_10) {
  char s1[] = "There are over 500 starfish in the bathroom drawer.";
  char s2[] = "500";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_11) {
  char s1[] = " ja;093 a 9 a9 aw aalkw";
  char s2[] = "8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_12) {
  char s1[] = "Carol drank the blood as if she were a vampire.";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_13) {
  char s1[] = "Carol \n\tdrank the blood as if she were a vampire.";
  char s2[] = "\n\t";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

START_TEST(strstr_14) {
  char s1[] = "His ultimate dream fantasy consisted of being content and sleeping eight hours in a row.";
  char s2[] = "dream of sleeping";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
} END_TEST

Suite *test_strstr() {
    Suite *test_set = suite_create("s21_strstr");
    TCase *test_group = tcase_create("strstr_test_group");

    tcase_add_test(test_group, strstr_1);
    tcase_add_test(test_group, strstr_2);
    tcase_add_test(test_group, strstr_3);
    tcase_add_test(test_group, strstr_4);
    tcase_add_test(test_group, strstr_5);
    tcase_add_test(test_group, strstr_6);
    tcase_add_test(test_group, strstr_7);
    tcase_add_test(test_group, strstr_8);
    tcase_add_test(test_group, strstr_9);
    tcase_add_test(test_group, strstr_10);
    tcase_add_test(test_group, strstr_11);
    tcase_add_test(test_group, strstr_12);
    tcase_add_test(test_group, strstr_13);
    tcase_add_test(test_group, strstr_14);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
