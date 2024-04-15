#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *arr1, int *n);
void output(int *arr1, int n);
void addition(int *arr1, int *arr2, int len1, int len2);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main()
{
    int num1[LEN], num2[LEN], res[LEN+1];
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    input(num1, &n1);
    input(num2,&n2);
    if(n1 < n2) {
        printf("n/a");
        return -1;
    }
    sum(num1, n1, num2, n2, res, &n3);
    output(res, n3);
    printf("\n");
    sub(num1, n1, num2, n2, res, &n3);
    output(res, n3);
    return 0;
}

int input(int *arr1, int *n) {
    char ch1;
    int flag = 0;
    while(!flag) {
        if (scanf("%d%c", arr1, &ch1) != 2 && ch1 == '\n') {
            flag = 1;
        } else {
            if(ch1 == '\n')
                flag = 1;
            arr1++;
            (*n)++;
        }
    }
    return 0;
}

void output(int *arr, int n) {
    if(arr[0] == 0) {
    for (int i = 1; i < n; i++) {
        if ( i == 1 )
            printf("%d", arr[i]);
        else
            printf(" %d", arr[i]);
        }
    }
}


void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    for (int i = 0; i < len1; i++) {
        result[i + 1] = buff1[i];
    }
    for (int i = len2 - 1, j = 1; i > -1; i--, j++) {
            if ( (buff2[i] + result[len1 - j + 1]) > 9  ) {
            result[len1 - j]++;
            result[len1 - j + 1] = buff2[i] + result [len1 - j + 1] - 10;
        }
        else {
            result[len1 - j + 1] = buff2[i] + result[len1 - j + 1];
        }
   }
    *result_length = len1+1;
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    for (int i = 0; i < len1; i++) {
        result[i + 1] = buff1[i];
    }
    for (int i = len2 - 1, j = 1; i > -1; i--, j++) {
            if ( (result[len1 - j + 1] - buff2[i]) < 0  ) {
            result[len1 - j]--;
            result[len1 - j + 1] = result [len1 - j + 1] - buff2[i] + 10;
        }
        else {
            result[len1 - j + 1] = result [len1 - j + 1] - buff2[i];
        }
   }
    *result_length = len1+1;
}
