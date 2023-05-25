CC = gcc -Wall -Werror -Wextra

s21_string_tests: s21_string.o s21_string_tests.o
	$(CC) s21_string.o s21_string_tests.o -o s21_string_tests
	rm -rf *.o

s21_string_tests.o: s21_string_tests.c 
	$(CC) -c s21_string_tests.c 

s21_string.o: s21_string.c
	$(CC) -c s21_string.c

clean:
	rm -rf *.o
	rm -rf s21_string_test
