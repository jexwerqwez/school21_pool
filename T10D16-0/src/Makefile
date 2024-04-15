CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) s21_string.c
s21_string_test.o: s21_string_test.c
	$(CC) $(CFLAGS) s21_string_test.c

strlen_tests: s21_string_strlen_test.o s21_string.o
	$(CC) s21_string_strlen_test.o s21_string.o -o ../build/Quest_1
s21_string_strlen_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRLEN_TEST s21_string_test.c -o s21_string_strlen_test.o

strcmp_tests: s21_string_strcmp_test.o s21_string.o
	$(CC) s21_string_strcmp_test.o s21_string.o -o ../build/Quest_2
s21_string_strcmp_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRCMP_TEST s21_string_test.c -o s21_string_strcmp_test.o

strcpy_tests: s21_string_strcpy_test.o s21_string.o
	$(CC) s21_string_strcpy_test.o s21_string.o -o ../build/Quest_3
s21_string_strcpy_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRCPY_TEST s21_string_test.c -o s21_string_strcpy_test.o

strcat_tests: s21_string_strcat_test.o s21_string.o
	$(CC) s21_string_strcat_test.o s21_string.o -o ../build/Quest_4
s21_string_strcat_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRCAT_TEST s21_string_test.c -o s21_string_strcat_test.o

strchr_tests: s21_string_strchr_test.o s21_string.o
	$(CC) s21_string_strchr_test.o s21_string.o -o ../build/Quest_5
s21_string_strchr_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRCHR_TEST s21_string_test.c -o s21_string_strchr_test.o

strstr_tests: s21_string_strstr_test.o s21_string.o
	$(CC) s21_string_strstr_test.o s21_string.o -o ../build/Quest_6
s21_string_strstr_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRSTR_TEST s21_string_test.c -o s21_string_strstr_test.o

strtok_tests: s21_string_strtok_test.o s21_string.o
	$(CC) s21_string_strtok_test.o s21_string.o -o ../build/Quest_7
s21_string_strtok_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D S21_STRTOK_TEST s21_string_test.c -o s21_string_strtok_test.o


clean:
	rm -rf *.o

rebuild: rm -rf *.o all
