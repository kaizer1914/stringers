#include "s21_string_tests.h"

START_TEST(strtok_1) {
  char s1[] = "The crowd yells and screams for more memes.";
  char s2[] = "The crowd yells and screams for more memes.";
  char s3[] = " ";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_2) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_3) {
  char s1[] = "Not all people who wander are lost.";
  char s2[] = "Not all people who wander are lost.";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_4) {
  char s1[] = "They desperately needed another drummer since the current one only knew how to play bongos.";
  char s2[] = "They desperately needed another drummer since the current one only knew how to play bongos.";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_5) {
  char s1[] = "I know many children ask for a pony, but I wanted a bicycle with rockets strapped to it.";
  char s2[] = "I know many children ask for a pony, but I wanted a bicycle with rockets strapped to it.";
  char s3[] = "I know many children ask for a pony, but I wanted a bicycle with rockets strapped to it.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_6) {
  char s1[] = "In the end, he realized he could see sound and hear words.";
  char s2[] = "In the end, he realized he could see sound and hear words.";
  char s3[] = ",";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "\tHe was sitting in a trash can with high street class.";
  char s2[] = "\tHe was sitting in a trash can with high street class.";
  char s3[] = "\t";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
} END_TEST

START_TEST(strtok_9) {
  char s1[] = "While all her friends were positive that Mary had a sixth sense, she knew she actually had a seventh sense.";
  char s2[] = "While all her friends were positive that Mary had a sixth sense, she knew she actually had a seventh sense.";
  char s3[] = "Q";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
} END_TEST

START_TEST(strtok_10) {
  char s1[] = "She opened up her third bottle of wine of the night.";
  char s2[] = "She opened up her third bottle of wine of the night.";
  char s3[] = ".";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
} END_TEST

Suite *test_strtok() {
    Suite *test_set = suite_create("s21_strtok");
    TCase *test_group = tcase_create("strtok_test_group");

    tcase_add_test(test_group, strtok_1);
    tcase_add_test(test_group, strtok_2);
    tcase_add_test(test_group, strtok_3);
    tcase_add_test(test_group, strtok_4);
    tcase_add_test(test_group, strtok_5);
    tcase_add_test(test_group, strtok_6);
    tcase_add_test(test_group, strtok_7);
    tcase_add_test(test_group, strtok_8);
    tcase_add_test(test_group, strtok_9);
    tcase_add_test(test_group, strtok_10);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
