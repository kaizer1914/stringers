#include "s21_string_tests.h"

START_TEST(memcmp_1) {
    char s1[] = "Patricia loves the sound of nails strongly pressed against the chalkboard.";
    char s2[] = "Patricia loves the sound of nails strongly pressed against the chalkboard.";
    s21_size_t n = 30;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_2) {
    char s1[] = "The gruff old man sat in the back of the bait shop grumbling to himself as he scooped out a handful of worms.";
    char s2[] = "The gruff old man sat in the back of the bait shop grumbling to himself as he scooped out a handful of worms.";
    s21_size_t n = 0;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_3) {
    char s1[] = "Sometimes it is better to just walk away from things and go back to them later when youre in a better frame of mind.";
    char s2[] = "Sometimes it is better to just walk away from things and go back to them later when youre in a better frame of mind.";
    s21_size_t n = 14;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_4) {
    char s1[] = "Hello, world!";
    char s2[] = "Hello";
    s21_size_t n = 6;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_5) {
    char s1[] = "Hello, world!";
    char s2[] = "Another world!";
    s21_size_t n = 14;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_6) {
    char s1[] = "";
    char s2[] = "";
    s21_size_t n = 1;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_7) {
    char s1[] = "Flesh-colored yoga pants were far worse than even he feared.";
    char s2[] = "The three-year-old girl ran down the beach as the kite flew behind her.";
    s21_size_t n = 15;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_8) {
    char s1[] = "Her daily goal was to improve on yesterday.";
    char s2[] = "She can live her life however she wants as long as she listens to what I have to say.";
    s21_size_t n = 30;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_9) {
    char s1[] = "There were white out conditions in the town; subsequently, the roads were impassable.";
    char s2[] = "The ice-cream trucks bring back bad memories for all of us.";
    s21_size_t n = 3;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

START_TEST(memcmp_10) {
    char s1[] = "Most shark attacks occur about 10 feet from the beach since that's where the people are.";
    char s2[] = "Everything was going so well until I was accosted by a purple giraffe.";
    s21_size_t n = 0;
    int n1 = memcmp(s1, s2, n);
    n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
    int n2 = s21_memcmp(s1, s2, n);
    n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
    ck_assert_int_eq(n1, n2);
} END_TEST

Suite *test_memcmp() {
    Suite *test_set = suite_create("s21_memcmp");
    TCase *test_group = tcase_create("memcmp_test_group");

    tcase_add_test(test_group, memcmp_1);
    tcase_add_test(test_group, memcmp_2);
    tcase_add_test(test_group, memcmp_3);
    tcase_add_test(test_group, memcmp_4);
    tcase_add_test(test_group, memcmp_5);
    tcase_add_test(test_group, memcmp_6);
    tcase_add_test(test_group, memcmp_7);
    tcase_add_test(test_group, memcmp_8);
    tcase_add_test(test_group, memcmp_9);
    tcase_add_test(test_group, memcmp_10);

    suite_add_tcase(test_set, test_group);

    return test_set;
}
