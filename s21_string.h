#ifndef S21_STRING_H
#define S21_STRING_H

// #include <stdio.h>

#define s21_NULL ((void *)0);

typedef unsigned long s21_size_t;

s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

#endif