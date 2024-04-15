#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

// строка и подсчитанная длина (человеком)
void s21_strlen_test(const char *str, int n);
// строки и подсчитанная между ними разница (человеком)
void s21_strcmp_test(char *str1, char *str2, int n);
// строки и их длина
void s21_strcpy_test(char *str1, char *str2, int len1, int len2);
// тестовые строки, полученная строка (человеком), их суммарная длина
void s21_strcat_test(char *str1, char *str2, char *str3, int len);
// строка, символ, найден он или нет (1, 0) и позиция (подсчитанная человеком)
void s21_strchr_test(char* str, char ch, int flag, int pos);
// строка1, строка2, найдена он или нет (1, 0) и позиция (подсчитанная человеком)
void s21_strstr_test(char* str1, char* str2, int flag, int pos);
// строка1, разделитель, правильное разбиение(человек)
void s21_strtok_test(char* str1, char* sep, char *sepres);

int main() {
    #ifdef S21_STRLEN_TEST
    printf("Строка 'stdio.h':\n");
    s21_strlen_test("stdio.h", 7);
    printf("Строка 'why\\0is it so difficult':\n");
    s21_strlen_test("why\0is it so difficult", 26);
    printf("Строка 'default buffer text\\n':\n");
    s21_strlen_test("default buffer text\n", 21);
    #endif

    #ifdef S21_STRCMP_TEST
    printf("Строки 'string' и 'string':\n");
    s21_strcmp_test("string", "string", 0);
    printf("Строки 'string_pobolshe\\0' и 'string_pobolshe':\n");
    s21_strcmp_test("string_pobolshe\0", "string_pobolshe", 2);
    printf("Строки 'za\\0warudo' и 'za warudo':\n");
    s21_strcmp_test("za\0warudo", "za warudo", 2);
    printf("Строки 'abcd' и 'abcde':\n");
    s21_strcmp_test("abcd", "abcde", -101);
    #endif

    #ifdef S21_STRCPY_TEST
    printf("Строки 'string' и 'abracadabra':\n");
    s21_strcpy_test("string", "abracadabra",
        sizeof("string") / sizeof(char), sizeof("abracadabra") / sizeof(char));
    printf("Строки 'return more' и 'less':\n");
    s21_strcpy_test("return more", "less",
        sizeof("return more") / sizeof(char), sizeof("less") / sizeof(char));
    printf("Строки '\\0\\0\\0' и '\\0\\0\\0':\n");
    s21_strcpy_test("\0\0\0", "\0\0\0",
        sizeof("\0\0\0") / sizeof(char), sizeof("\0\0\0") / sizeof(char));
    #endif

    #ifdef S21_STRCAT_TEST
    printf("Строки 'present day ' и 'present time\\n'\n");
    s21_strcat_test("present day ", "present time\n", "present day present time\\n",
            sizeof("present day") / sizeof(char) + sizeof("present time\n") / sizeof(char));
    printf("Строки 'abo' и 'bus'\n");
    s21_strcat_test("abo", "bus", "abobus", sizeof("abo") / sizeof(char) + sizeof("bus") / sizeof(char));
    printf("Строки 'i found\\0one piece' и ' or not?'\n");
    s21_strcat_test("i found\0one piece ", " or not?", "i found one piece or\\0not?",
            sizeof("i found\\0one piece") / sizeof(char) + sizeof(" or not?") / sizeof(char));
    #endif

    #ifdef S21_STRCHR_TEST
    printf("Поиск символа '3' в строке '9876543210'\n");
    s21_strchr_test("9876543210", '3', 1, 7);
    printf("Поиск символа 'y' в строке 'qwer\\ty'\n");
    s21_strchr_test("qwer\ty'", 'y', 1, 8);
    printf("Поиск символа 'b' в строке 'pneumonoultramicroscopicsilicovolcanoconiosis'\n");
    s21_strchr_test("pneumonoultramicroscopicsilicovolcanoconiosis", 'b', 0, 8);
    printf("Поиск символа 'v' в строке 'return\\v\n");
    s21_strchr_test("return\v", 'v', 1, 8);
    #endif

    #ifdef S21_STRSTR_TEST
    printf("Поиск строки 'pictures' в строке 'Taking pictures of the sunset'\n");
    s21_strstr_test("Taking pictures of the sunset", "pictures", 1, 8);
    printf("Поиск строки 'diamonds' в строке 'distribution of\\0diamonds on spawn'\n");
    s21_strstr_test("distribution of\0diamonds on spawn", "diamonds", 1, 18);
    printf("Поиск строки 'kill' в строке 'Verter\\t\\t\\t\\t\\t\\twill kill us all'\n");
    s21_strstr_test("Verter\t\t\t\t\t\twill kill us all", "kill", 1, 24);
    printf("Поиск строки 'success' в строке 'results of the 15th day'\n");
    s21_strstr_test("results of the 15th day", "success", 0, 0);
    #endif

    #ifdef S21_STRTOK_TEST
    printf("Исходная строка 'белый, синий, красный' c символом разбиения ','\n");
    s21_strtok_test("белый, синий, красный", ",", "белый");
    printf("Исходная строка '4444' c символом разбиения '4'\n");
    s21_strtok_test("4444", "4", "");
    printf("Исходная строка '\\0Tra\\0ta\\0\\0ta\\0ta\\0ta' c символом разбиения '\\0'\n");
    s21_strtok_test("\0Tra\0ta\0ta\0ta\0ta", "\0", "Tra");
    #endif
    return 0;
}

void s21_strlen_test(const char *str, int n) {
    printf("Программная длина = %d\n", s21_strlen(str));
    printf("Подсчитанная длина = %d\n", n);
    if (s21_strlen(str) == n) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test(char *str1, char *str2, int n) {  // 0 - строки равны; 1+ - различны
    if (s21_strcmp(str1, str2) == 0) {
        if (n == s21_strcmp(str1, str2)) {
            printf("Входная и выходная строки ожидаемо равны\n");
            printf("SUCCESS\n");
        } else {
            printf("Входная и выходная строки неожиданно равны\n");
            printf("FAIL\n");
        }
    } else {
        if (n == s21_strcmp(str1, str2)) {
            printf("Входная и выходная строки ожидаемо отличаются\n");
            printf("SUCCESS\n");
        } else {
            printf("Входная и выходная строки неожиданно отличаются\n");
            printf("FAIL\n");
        }
    }
}

void s21_strcpy_test(char *str1, char *str2, int len1, int len2) {
    str1 = (char*)malloc(len1+1);
    if (len1 < len2) {
        printf("Копируемая строка больше начальной\n");
        printf("FAIL\n");
    } else if (s21_strcmp(s21_strcpy(str1, str2), str1) == 0) {
        printf("Результат копирования: %s\n", str2);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    free(str1);
}

void s21_strcat_test(char *str1, char *str2, char *str3, int len) {
    char* res = (char*)malloc(len);
    s21_strcat(res, str1);
    s21_strcat(res, str2);
    printf("Ожидаемый результат конкатенации %s\n", str3);
    printf("Программный результат конкатенации %s\n", res);
    if (s21_strcmp(res, str3) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    free(res);
}

void s21_strchr_test(char* str, char ch, int flag, int pos) {
    char* res = s21_strchr(str, ch);
    if (res == NULL && flag == 0) {
        printf("Символ не найден\n");
        printf("SUCCESS\n");
    } else if (res == NULL && flag == 1) {
        printf("Символ не найден, но в строке он есть\n");
        printf("FAIL\n");
    } else {
        if ((res - str + 1) == pos) {
            printf("Символ найден\n");
            printf("SUCCESS\n");
        } else {
            printf("Символ найден, но не на той позиции\n");
            printf("FAIL\n");
        }
    }
}

void s21_strstr_test(char* str1, char* str2, int flag, int pos) {
    char* res = s21_strstr(str1, str2);
    if (res == NULL && flag == 0) {
        printf("Строка не найдена\n");
        printf("SUCCESS\n");
    } else if (res == NULL && flag == 1) {
        printf("Строка не найдена, но она есть\n");
        printf("FAIL\n");
    } else {
        if ((res - str1 + 1) == pos) {
            printf("Строка найдена\n");
            printf("SUCCESS\n");
        } else {
            printf("Строка найдена, но не на той позиции\n");
            printf("FAIL\n");
        }
    }
}

void s21_strtok_test(char* str1, char* sep, char *sepres) {
    if (s21_strcmp(s21_strtok(str1, sep), sepres) == 0) {
        printf("Результат разбиения: %s\n", s21_strtok(str1, sep));
        printf("SUCCESS\n");
    } else {
        printf("Результат разбиения: %s\n", s21_strtok(str1, sep));
        printf("FAIL\n");
    }
}
