#include <stdio.h>
#include <stdlib.h>

int s21_strcmp(char *str1, char *str2);

int main(int argc, char* argv[]) {
    int n;
    argc += 0;
    if (s21_strcmp(argv[1], "-w") != 0) {
        printf("n/a");
    } else {
        scanf("%d", &n);
        char text[100];
        text[n] = '\0';
        for (int i = 0; text[i] != '\0'; i++)
            scanf("%c", &text[i]);
        puts(text);
    }
    return 0;
}

int s21_strcmp(char *str1, char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    return *str1 - *str2;
}
