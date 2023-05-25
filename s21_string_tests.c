#include <stdio.h>
#include <string.h> 

#include "s21_string.h"

int main() {
    // s21_size_t *tr;
    // s21_size_t a = 3;
    // tr = &a;
    // printf("%ld", *tr);

   // Исходный массив
   unsigned char src[15] = {64, 65, 66, 67, 68, 69, 70, 71 , 72};
   // Переменная, в которую будет сохранен указатель
   // на искомый символ.
    // for (int i = 0; i < 15; i++) {
    //     src[i] = i;
    // }

   char *sym;

   // Вывод исходного массива
   printf ("src old: %s\n",src);

   // Поиск требуемого символа
   sym = memchr (src, 'B', 10);

   // Если требуемый символ найден, то заменяем его
   // на символ '!'
   if (sym != NULL)
      sym[0]='!';

   // Вывод исходного массива
   char st[20];
//    char *cc = "ss";
   char *ccc = "abcdefg";
   strcpy (st,"To be ");
   strncat(st, ccc, 4); 

//    strtok(cc, "t");
   printf ("src new: %s\n",src);

   printf("%d\n", (int)s21_strlen((char*)src));
//    printf("%s\n", strtok(cc, "t"));
   printf("%s\n", st);
   printf("%s\n", s21_strncat(st, ccc, 4));
   return 0;
}