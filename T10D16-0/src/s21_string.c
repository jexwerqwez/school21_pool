#include <stdio.h>
#include "s21_string.h"
#include <stdlib.h>

int s21_strlen(const char *str) {
    int len = 0;
    for (; *(str + len); len++) {}
    return len;
}

int s21_strcmp(char *str1, char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    return *str1 - *str2;
}

char* s21_strcpy(char *str1, char *str2) {
    char *start = str1;
    while (*str2 != '\0')
        *str1++ = *str2++;
    return start;
}

char* s21_strcat(char *str1, char *str2) {
    char* begin = str1;
    while (*str1)
        str1++;
    while ((*str1++ = *str2++) != '\0') {}
    *str1 = '\0';
    return begin;
}

char* s21_strchr(char *str, char ch) {
    while (*str) {
        if (*str == ch)
            return str;
        else
            str++;
    }
    return NULL;
}

char* s21_strstr(char *str1, char *str2) {
    for (int i = 0; str1[i] != '\0'; i++) {
        int tmp = i;
        int j = 0;
        while (str1[i++] == str2[j++]) {
            if (str2[j] == '\0')
                return &str1[tmp];
        }
        i = tmp;
    }
    return NULL;
}

char* s21_strtok(char *str, char* sep) {
    char* start = NULL;
    if (str != NULL)
        start = str;
    char* res = (char*)malloc(s21_strlen(str) + 1);
    int i = 0;
    for (; start[i] != '\0'; i++) {
        if (start[i] != *sep) {
            res[i] = start[i];
        } else {
            res[i] = '\0';
            start += (i+1);
            free(res);
            return res;
        }
    }
    res[i] = '\0';
    start = NULL;
    free(res);
    return res;
}
