CC = gcc -Wall -Werror -Wextra -std=c11
CHECK_FLAGS = $(shell pkg-config --cflags --libs check)
COVERAGE=-fprofile-arcs -ftest-coverage

all: clean s21_string.a test gcov_report

s21_string.a: s21_string.c s21_string.h
	$(CC) $(COVERAGE) -c s21_string.c
	ar rcs s21_string.a s21_string.o
	rm -rf s21_string.o

test: s21_string.a s21_string_tests.c s21_string_tests.h test_*.c
	$(CC) $(COVERAGE) -c s21_string_tests.c test_*.c
	$(CC) $(COVERAGE) -o s21_string_tests s21_string_tests.o test_*.o -L. s21_string.a $(CHECK_FLAGS)
	rm -rf s21_string_tests.o test_*.o
	./s21_string_tests; sleep 1

gcov_report: test
	gcov s21_string_tests.gcda
	gcovr --html-details -o report.html
	rm -rf *.gcno *.gcov *.gcda

clean:
	rm -rf *.o *.a *.html *.css *.gcno *.gcov *.gcda *.log
	rm -rf s21_string_tests

format:
	clang-format -i --style=Google *.c *.h

check:
	clang-format -n --style=Google *.c *.h
	cppcheck --enable=all --force *.h *.c
	if [[ `uname` == "Darwin" ]]; then leaks --atExit -- ./s21_string_tests; fi
	if [[ `uname` == "Linux" ]]; then valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./s21_string_tests; sleep 1; fi

rebuild: clean all
