#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

int s21_strlen(const char *str);
int s21_strcmp(char *str1, char *str2);
char* s21_strcpy(char *str1, char *str2);
char* s21_strcat(char *str1, char *str2);
char* s21_strchr(char *str, char ch);
char* s21_strstr(char *str1, char *str2);
char* s21_strtok(char *str, char* sep);

#endif  // SRC_S21_STRING_H_
