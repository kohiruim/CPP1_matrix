CC= g++
CFLAGS= -Wall -Wextra -Werror -std=c++17
SOURCES =  s21_matrix_oop.cc
OBJECTS = s21_matrix_oop.o
TEST_LIBS = -lgtest -pthread


all: clean s21_matrix_oop.a test

s21_matrix_oop.a:
	$(CC) $(CFLAGS) $(SOURCES) -c
	ar rcs s21_matrix_oop.a $(OBJECTS)

test: clean s21_matrix_oop.a
	$(CC) $(CFLAGS) test.cc s21_matrix_oop.a $(TEST_LIBS) -o test.o
	./test.o

gcov_report: all
	g++ $(SOURCES) test.cc $(TEST_LIBS)  --coverage -o gсov_report.o
	./gсov_report.o
	lcov -t test.o -o s21_matrix_tests.info -c -d .
	genhtml -o report s21_matrix_tests.info

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.h *.cc
	rm -rf .clang-format

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch *.info *.html *.css test *.txt test.info test.dSYM report