#include "s21_string_tests.h"

START_TEST(strncmp_1) {
   char s1[] = "Patricia found the meaning of life in a bowl of Cheerios.";
   char s2[] = "Patricia found the meaning of life in a bowl of Cheerios.";
   s21_size_t n = 14;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_2) {
   char s1[] = "";
   char s2[] = "";
   s21_size_t n = 1;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_3) {
   char s1[] = "She finally understood that grief was her love with no place for it to go.";
   char s2[] = "";
   s21_size_t n = 1;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_4) {
   char s1[] = "";
   char s2[] = "She was amazed by the large chunks of ice washing up on the beach.";
   s21_size_t n = 1;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_5) {
   char s1[] = "1242434246364377659";
   char s2[] = "1242434246364377659";
   s21_size_t n = 19;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_6) {
   char s1[] = "g124243425";
   char s2[] = "124243424";
   s21_size_t n = 0;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_7) {
   char s1[] = "He shaved the peach to prove a point.";
   char s2[] = "Nudist colonies shun fig-leaf couture.";
   s21_size_t n = 10;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_8) {
   char s1[] = "The fox in the tophat whispered into the ear of the rabbit.";
   char s2[] = "The glacier came alive as the climbers hiked closer.";
   s21_size_t n = 4;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_9) {
   char s1[] = "The golden retriever loved the fireworks each Fourth of July.";
   char s2[] = "The Great Dane looked more like a horse than a dog.";
   s21_size_t n = 5;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_10) {
   char s1[] = "\tShe saw the brake lights, but not in time.";
   char s2[] = "\tSiri became confused when we reused to follow her directions.";
   s21_size_t n = 2;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(strncmp_11) {
   char s1[] = "Now I\n need to\t ponder my existence and ask myself if I truly real";
   char s2[] = "Now I\n need to\t ponder";
   s21_size_t n = 12;
   int n1 = strncmp(s1, s2, n);
   n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
   int n2 = s21_strncmp(s1, s2, n);
   n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
   ck_assert_int_eq(n1, n2);
} END_TEST

Suite *test_strncmp() {
   Suite *test_set = suite_create("s21_strncmp");
   TCase *test_group = tcase_create("strncmp_test_group");

   tcase_add_test(test_group, strncmp_1);
   tcase_add_test(test_group, strncmp_2);
   tcase_add_test(test_group, strncmp_3);
   tcase_add_test(test_group, strncmp_4);
   tcase_add_test(test_group, strncmp_5);
   tcase_add_test(test_group, strncmp_6);
   tcase_add_test(test_group, strncmp_7);
   tcase_add_test(test_group, strncmp_8);
   tcase_add_test(test_group, strncmp_9);
   tcase_add_test(test_group, strncmp_10);
   tcase_add_test(test_group, strncmp_11);

   suite_add_tcase(test_set, test_group);

   return test_set;
}
