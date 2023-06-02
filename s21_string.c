#include <stdio.h>
#include <stdlib.h>

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
    for(s21_size_t i=0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
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
    for (int i = s21_strlen(str); i >= 0; i--) {
        if ((int)str[i] == c) {
            newstr = (char*)(str + i); 
            break;
        }
    }
    return newstr;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *newstr = s21_NULL;
    for (s21_size_t i = 0; i <= s21_strlen(haystack); i++) {
        if (!s21_strncmp(haystack + i, needle, s21_strlen(needle))) {
            newstr = (char*)(haystack+i);
            break;
        }
    }
    return newstr;
}

char *s21_strtok(char *str, const char *delim) {
  char *res;
  static char *new;
  int equal = 1;
  if (str == s21_NULL)
    str = new;
  if (str != s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str) && equal; i++) {
      equal = 0;
      for (s21_size_t j = 0; j < s21_strlen(delim); j++)
        if (str[i] == delim[j]) {
          equal = 1;
          break;
        }
      if (!equal)
        res = str + i;
    }
    if (equal)
      res = s21_NULL;
    else {
      for (s21_size_t i = 0; i < s21_strlen(res) && !equal; i++) {
        equal = 0;
        for (s21_size_t j = 0; j < s21_strlen(delim); j++)
          if (res[i] == delim[j]) {
            equal = 1;
            res[i] = '\0';
            new = res + i + 1;
            break;
          }
      }
      if (!equal)
        new = s21_NULL;
    }
  } else
    res = s21_NULL;
  return res;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    char *ch = s21_NULL;
    if (s21_strlen((char*)str) >= n) {
        for (s21_size_t i = 0; i < n; i++)
        {
            if (*(char*)str == c) {
                ch = (char*)str;
                break;
            }
            str++;
        }
    }
    return ch;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int res = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (*(char*)str1 != *(char*)str2 ) {
            res = *(char*)str1 - *(char*)str2;
            break;
        }
        str1++;
        str2++;
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    for (s21_size_t i = 0; i < n; i++ ) {
        *(char*)(dest + i) = *(char*)(src +i);
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    s21_size_t length = sizeof((unsigned char*)str);
    if (length >= n) {
        for (s21_size_t i = 0; i < n; i++) {
            *(unsigned char*)(str + i) = (unsigned char) c;
        }
    }
    else {
        fprintf(stderr, "Error: writing %d bytes into a region of size %d overflows the destination\n", (int)n, (int)length+1);
        exit(1);
    }
    return str;
}

char *s21_strerror(int errnum) {
    char *ERRORS[] = ERROR_LIST;
    char *result = UNKNOWN_ERROR;  // replace s21_sprinf();
    if (errnum >= 0 && errnum < ERRORS_COUNT)
        result = ERRORS[errnum];
    return result;
}

void *s21_to_lower(const char *str) {
    char *res = s21_NULL;
        if (str) {
            res = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
            if (res) {
                s21_strncpy(res, str, s21_strlen(str) + 1);
                for (char* tmp = res; *tmp; tmp++) {
                    if (*tmp >= 'A' && *tmp <= 'Z') 
                        *tmp += 32;
                }
            }
        }
    return res;
}

void *s21_to_upper(const char *str) {
    char *res = s21_NULL;
        if (str) {
            res = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
            if (res) {
                s21_strncpy(res, str, s21_strlen(str) + 1);
                for (char* tmp = res; *tmp; tmp++) {
                    if (*tmp >= 'a' && *tmp <= 'z') 
                        *tmp -= 32;
                }
            }
        }
    return res;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
    char *res =
        malloc(sizeof(char) * (s21_strlen(src) + s21_strlen(str)) + sizeof(char));
    if (start_index <= s21_strlen(src)) {
        for (s21_size_t i = 0; i < start_index; i++)
        res[i] = src[i];
        for (s21_size_t i = 0; i < s21_strlen(str); i++)
        res[start_index + i] = str[i];
        for (s21_size_t i = start_index; i < s21_strlen(src); i++)
        res[s21_strlen(str) + i] = src[i];
        res[s21_strlen(src) + s21_strlen(str)] = '\0';
    } else {
        free(res);
        res = s21_NULL;
    }
    return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = s21_NULL;
    s21_size_t srclen = s21_strlen(src);
    s21_size_t trimlen = s21_strlen(trim_chars);
    int start_index, end_index, equal = 1;
    for (s21_size_t i = 0; i < srclen && equal; i++) {
        equal = 0;
        for (s21_size_t j = 0; j < trimlen; j++)
        if (src[i] == trim_chars[j])
            equal = 1;
        if (!equal)
        start_index = i;
    }
    if (!equal) {
        equal=1;
        for (int i = (int)srclen - 1; i >= 0 && equal; i--) {
        equal = 0;
        for (s21_size_t j = 0; j < trimlen; j++)
            if (src[i] == trim_chars[j])
            equal = 1;
        if (!equal)
            end_index = i;
        }
    }
    if (!equal) {
        res = malloc(sizeof(char) * (end_index - start_index + 2));
        for (int i = (int)start_index; i <= (int)end_index; i++)
        res[i - start_index] = src[i];
        res[end_index - start_index + 1] = '\0';
    }
    return res;
}
