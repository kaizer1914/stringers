#include "s21_string_tests.h"

START_TEST(strncat_1) {
   char s1[100] = "The doll spun around in circles in hopes of coming alive.";
   char s2[100] = "The doll spun around in circles in hopes of coming alive.";
   char s3[] = "Jerry liked to look at paintings while eating garlic ice cream.";
   s21_size_t n = 10;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_2) {
   char s1[100] = "Improve your goldfish's physical fitness by getting him a bicycle.";
   char s2[100] = "Improve your goldfish's physical fitness by getting him a bicycle.";
   char s3[] = "\0";
   s21_size_t n = 1;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_3) {
   char s1[100] = "Patricia loves the sound of nails strongly pressed against the chalkboard.";
   char s2[100] = "Patricia loves the sound of nails strongly pressed against the chalkboard.";
   char s3[] = "\n\0\\color\0\\couple\t";
   s21_size_t n = 12;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_4) {
   char s1[100] = "There was no ice cream in the freezer, nor did they have money to go to the store.";
   char s2[100] = "There was no ice cream in the freezer, nor did they have money to go to the store.";
   char s3[] = "";
   s21_size_t n = 0;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_5) {
   char s1[40] = "";
   char s2[40] = "";
   char s3[] = "He spiked his hair green to support his iguana.";
   s21_size_t n = 13;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_6) {
   char s1[15] = "";
   char s2[15] = "";
   char s3[] = "";
   s21_size_t n = 10;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_7) {
   char s1[100] = "He spiked\0 his hair green to\0 support his iguana.";
   char s2[100] = "He spiked\0 his hair green to\0 support his iguana.";
   char s3[] = "Today \nI \0dressed my unicorn in preparation for the race.";
   s21_size_t n = 15;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_8) {
   char s1[20] = "Hello, world!";
   char s2[20] = "Hello, world!";
   char s3[] = "\0\0\0\0";
   s21_size_t n = 4;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_9) {
   char s1[50] = "Hello, world!\0\0\0";
   char s2[50] = "Hello, world!\0\0\0";
   char s3[] = "Luke, I am your father...";
   s21_size_t n = 0;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

START_TEST(strncat_10) {
   char s1[5] = "\0\0\0";
   char s2[5] = "\0\0\0";
   char s3[] = "\0";
   s21_size_t n = 5;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
} END_TEST

Suite *test_strncat() {
   Suite *test_set = suite_create("s21_strncat");
   TCase *test_group = tcase_create("strncat_test_group");

   tcase_add_test(test_group, strncat_1);
   tcase_add_test(test_group, strncat_2);
   tcase_add_test(test_group, strncat_3);
   tcase_add_test(test_group, strncat_4);
   tcase_add_test(test_group, strncat_5);
   tcase_add_test(test_group, strncat_6);
   tcase_add_test(test_group, strncat_7);
   tcase_add_test(test_group, strncat_8);
   tcase_add_test(test_group, strncat_9);
   tcase_add_test(test_group, strncat_10);

   suite_add_tcase(test_set, test_group);

   return test_set;
}
