#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "s21_string.h"

/* Функция тестирования какой-либо задачи */ 
START_TEST(strlen_1) {
   char *str = "Hello, world!";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
   char *str = "`1234567890-=;[],./~!@#$^&*()_+{}:|>?";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
   char str[] = "\0";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
   char str[] = "";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
   char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
   char str[] = "          00000000           ......  ";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
   char str[] = "\n\n\n\n\n\n\n\n\nababab\n\n\n\n\n";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_8) {
   char str[] = "\0\0\0\0\n";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
   char str[] = "\t\t";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_10) {
   char str[] = "\0Belfast";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_11) {
   char str[] = "sun \0 sun";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_12) {
   char str[30] = "30";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strncat_1) {
   char s1[30] = "Hello, world!";
   char s2[30] = "Hello, world!";
   char s3[] = "Hello, world!";
   s21_size_t n = 10;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_2) {
   char s1[30] = "Hello, world!";
   char s2[30] = "Hello, world!";
   char s3[] = "\0";
   s21_size_t n = 1;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_3) {
   char s1[30] = "Hello, world!";
   char s2[30] = "Hello, world!";
   char s3[] = "\n\0\\d\f\\g\7";
   s21_size_t n = 12;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_4) {
   char s1[30] = "Hello, world!";
   char s2[30] = "Hello, world!";
   char s3[] = "";
   s21_size_t n = 0;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_5) {
   char s1[30] = "";
   char s2[30] = "";
   char s3[] = "Hello, world!";
   s21_size_t n = 13;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_6) {
   char s1[100] = "";
   char s2[100] = "";
   char s3[] = "";
   s21_size_t n = 10;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_7) {
   char s1[100] = "Hello\0, world!";
   char s2[100] = "Hello\0, world!";
   char s3[] = "World\0 Hello.";
   s21_size_t n = 15;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_8) {
   char s1[100] = "Hello, world!";
   char s2[100] = "Hello, world!";
   char s3[] = "\0\0\0\0";
   s21_size_t n = 4;
   ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_9) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "Luke, I am your father...";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

/* Функция создания набора тестов */ 
Suite *test_strlen() {
   Suite *test_set = suite_create("s21_strlen");
   // Набор разбивается на группы тестов, разделённых по каким-либо критериям
   TCase *test_group = tcase_create("strlen_test_group");

   /* Добавление теста в группу тестов */ 
   tcase_add_test(test_group, strlen_1);
   tcase_add_test(test_group, strlen_2);
   tcase_add_test(test_group, strlen_3);
   tcase_add_test(test_group, strlen_4);
   tcase_add_test(test_group, strlen_5);
   tcase_add_test(test_group, strlen_6);
   tcase_add_test(test_group, strlen_7);
   tcase_add_test(test_group, strlen_8);
   tcase_add_test(test_group, strlen_9);
   tcase_add_test(test_group, strlen_10);
   tcase_add_test(test_group, strlen_11);
   tcase_add_test(test_group, strlen_12);

   /* Добавление теста в тестовый набор */ 
   suite_add_tcase(test_set, test_group);

   return test_set;
}

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

   suite_add_tcase(test_set, test_group);

   return test_set;
}

int main(void) {
   int fail = 0;
   Suite *s21_string_test[] = {
      test_strlen(), 
      test_strncat(),
   };

   for (int i = 0; i < 2; i++) {
      SRunner *test_set_runner = srunner_create(s21_string_test[i]);
      srunner_set_fork_status(test_set_runner, CK_NOFORK);
      srunner_run_all(test_set_runner, CK_NORMAL);

      fail += srunner_ntests_failed(test_set_runner);
      // Получаем количество проваленных тестов

      srunner_free(test_set_runner);
   }

   return fail == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
