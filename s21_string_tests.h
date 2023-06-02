#ifndef S21_STRING_TESTS_H
#define S21_STRING_TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "s21_string.h"

#define SUITE_COUNT 19

Suite *test_strlen();
Suite *test_strncat();
Suite *test_strchr();
Suite *test_strerror();
Suite *test_strncmp();
Suite *test_strncpy();
Suite *test_strcspn();
Suite *test_strpbrk();
Suite *test_strrchr();
Suite *test_strstr();
Suite *test_strtok();

Suite *test_memchr();
Suite *test_memcmp();
Suite *test_memcpy();
Suite *test_memset();

Suite *test_to_lower();
Suite *test_to_upper();
Suite *test_insert();
Suite *test_trim();

#endif