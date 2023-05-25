#include <stdio.h>
#include <string.h> 
#include <check.h>
#include <stdlib.h>

#include "s21_string.h"

Suite *test_strlen(void);

START_TEST(strlen_1) {
   char *str = "Hello, world!";
   ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *test_strlen(void) {
   Suite *test_set = suite_create("========= S21_STRLEN =========");
   TCase *test_group = tcase_create("strlen_test_group");
   // add other tests

   tcase_add_test(test_group, strlen_1);

   suite_add_tcase(test_set, test_group);
   return test_set;
}

int main(void) {
   int failed = 0;
   Suite *s21_string_test[] = {test_strlen()}; // add other suite

   for (int i = 0; i < 1; i++) {  // (&& failed == 0)
      SRunner *sr = srunner_create(s21_string_test[i]);

      srunner_set_fork_status(sr, CK_NOFORK);
      srunner_run_all(sr, CK_NORMAL);

      failed += srunner_ntests_failed(sr);
      srunner_free(sr);
   }
   printf("========= FAILED: %d =========\n", failed);

   return failed == 0 ? 0 : 1;
}
