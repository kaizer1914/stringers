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
    char *newstr = s21_NULL;
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
    for(s21_size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}

s21_size_t s21_strcspn (const char *str1, const char *str2) {
    s21_size_t ans = s21_strlen(str1);
    for (s21_size_t i = 0; i < s21_strlen(str2); i++ ) {
        for (s21_size_t j = 0; j < s21_strlen(str1); j++) {
            if (str2[i] == str1[j]) {
                if (ans > j) {ans = j;}
            }
        }
    }
    return ans;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *new = s21_NULL;
    s21_size_t num = s21_strlen(str1);
    for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
        for (s21_size_t j = 0; j < s21_strlen(str1); j++) {
            if (str2[i] == str1[j] && num > j) {
                new = (char*)(str1 + j);
                num = j;
            }
        }
    }
    return new;
}

char *s21_strrchr(const char *str, int c) {
    char *newstr = s21_NULL;
    for (int i = s21_strlen(str) - 1; i >= 0; i--) {
        if ((int)str[i] == c) {newstr = (char*)(str + i); break;}
    }
    return newstr;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *newstr = s21_NULL;
    for (s21_size_t i = 0; i < s21_strlen(haystack); i++) {
        if (!s21_strncmp(haystack + i, needle, s21_strlen(needle))) {newstr = (char*)(haystack+i);break;}
    }
    return newstr;
}

char *s21_strtok(char *str, const char *delim) {
    char *new = s21_NULL;
    s21_size_t num = s21_strlen(str);
    for (s21_size_t i = 0; i < s21_strlen(delim); i++) {
        for (s21_size_t j = 0; j < s21_strlen(str); j++) {
            if (delim[i] == str[j] && num > j) {
                new = (char*)(str + j);
                num = j;
            }
        }
    }
    return new;
}
