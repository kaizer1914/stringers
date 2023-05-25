#include <stdio.h>

#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t length = 0;
    for (int i = 0; str[i] != '\0'; i++) {length++;}
    return length;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t num = s21_strlen(dest);
        for (s21_size_t i = num; i < num + n; i++) {
            dest[i] = src[i - num];
            if (i == num + n) dest[i] = '\0';
        }
    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *newstr;
    for (int i= 0; str[i] == c || str[i] != '\0'; i++) {
        if ((int)str[i] == c) {newstr = (char*)(str + i); break;}
    }
    return newstr;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int res = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            res = str1[i] - str2[i]; 
            break;}
    }
    return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    for(s21_size_t i; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}


// void *s21_memchr(const void *str, int c, s21_size_t n) {
//     char *ch = s21_NULL;
//     // const unsigned char * str1 = str;
//     unsigned char * str1[]
//     for (s21_size_t i = 0; i < n; i++)
//     {
//         if (str1[i] == c) {ch = &str[i];}
//     }
//     return (void*) ch;
// }