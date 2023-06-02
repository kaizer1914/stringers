#include "s21_string_tests.h"

START_TEST(strcspn_1) {
   char s1[] = "The clouds formed beautiful animals in the sky that eventually created a tornado to wreak havoc.";
   char s2[] = "beautiful animals";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_2) {
   char s1[] = "Each person who knows you has a different perception of who you are.";
   char s2[] = "Each person who knows you has a different perception of who you are.";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_3) {
   char s1[] = "It took me too long to realize that the ceiling hadn't been painted to look like the sky.";
   char s2[] = "sky";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_4) {
   char s1[] = "";
   char s2[] = "The tears of a clown make my lipstick run, but my shower cap is still intact.";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_5) {
   char s1[] = "Today I heard something new and unmemorable.";
   char s2[] = "";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_6) {
   char s1[] = "Blue sounded too cold at the time and yet it seemed to work for gin.";
   char s2[] = "Blue";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_7) {
   char s1[] = "There was no telling what thoughts would come from the machine.";
   char s2[] = "telling what thoughts would come from the";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_8) {
   char s1[] = "";
   char s2[] = "";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_9) {
   char s1[] = "4712564712578";
   char s2[] = "471256471257F";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_10) {
   char s1[] = "Nothing is as cautiously cuddly as a pet porcupine.";
   char s2[] = "N";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

START_TEST(strcspn_11) {
   char s1[] = "Courage and stupidity were all he had.";
   char s2[] = "l";
   ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
} END_TEST

Suite *test_strcspn() {
   Suite *test_set = suite_create("s21_strcspn");
   TCase *test_group = tcase_create("strcspn_test_group");

   tcase_add_test(test_group, strcspn_1);
   tcase_add_test(test_group, strcspn_2);
   tcase_add_test(test_group, strcspn_3);
   tcase_add_test(test_group, strcspn_4);
   tcase_add_test(test_group, strcspn_5);
   tcase_add_test(test_group, strcspn_6);
   tcase_add_test(test_group, strcspn_7);
   tcase_add_test(test_group, strcspn_8);
   tcase_add_test(test_group, strcspn_9);
   tcase_add_test(test_group, strcspn_10);
   tcase_add_test(test_group, strcspn_11);

   suite_add_tcase(test_set, test_group);

   return test_set;
}
