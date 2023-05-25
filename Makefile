CC = gcc -Wall -Werror -Wextra

s21_string_tests: s21_string.o s21_string_tests.o
	$(CC) s21_string.o s21_string_tests.o -lcheck -o s21_string_tests
	rm -rf *.o

s21_string_tests.o: s21_string_tests.c 
	$(CC) -c s21_string_tests.c

s21_string.o: s21_string.c s21_string.h
	$(CC) -c s21_string.c

test_strlen.o: test_strlen.c test_strlen.h
	$(CC) -c test_strlen.c

clean:
	rm -rf *.o
	rm -rf s21_string_tests

rebuild: clean all
