#include "s21_string_tests.h"

START_TEST(strlen_1) {
    char *str = "He spiked his hair green to support his iguana.";
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
    char str[] = "Garlic \0ice-cream was \0her favorite.";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_12) {
    char str[30] = "3\t0";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *test_strlen() {
    Suite *test_set = suite_create("s21_strlen");
    TCase *test_group = tcase_create("strlen_test_group");

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

    suite_add_tcase(test_set, test_group);

    return test_set;
}