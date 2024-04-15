#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int input(int* mode, int* n, int* m);
void menu(int* mode, int n, int m);
void static_matrix(int** a, int n, int m);
void dynamic_first(int** a, int n, int m);  // Array of pointers to array segments within one buffer
void dynamic_second(int** a, int n, int m);  // Array of pointers to arrays
void dynamic_third(int** a1, int* a2, int n, int m);  // Array of pointers to segments of the second array
void output(int **a, int n, int m);
void transform(int *buf, int **matr, int n, int m);

int main(void) {
    int mode = 0;
    int n, m;
    if (input(&mode, &n, &m) != 0) {
        printf("n/a");
        return -1;
    } else {
        menu(&mode, n, m);
    }
    return 0;
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
       matr[i] = buf + i * m;
    }
}

void menu(int* mode, int n, int m) {
    if (*mode == 1) {
        int data_st[LEN][LEN];
        int* data[LEN];
        transform(*data_st, data, n, m);
        static_matrix(data, n, m);
        output(data, n, m);
    } else if (*mode == 2) {
        int** single_array_matrix = malloc(n * m * sizeof(int) + n * sizeof(int*));
        dynamic_first(single_array_matrix, n, m);
        output(single_array_matrix, n, m);
        free(single_array_matrix);
    } else if (*mode == 3) {
        int** pointer_array = malloc(n * sizeof(int*));
        dynamic_second(pointer_array, n, m);
        output(pointer_array, n, m);
        for (int i = 0; i < n; i++)
            free(pointer_array[i]);
        free(pointer_array);
    } else if (*mode == 4) {
        int** pointer_array1 = malloc(n * sizeof(int*));
        int* values_array = malloc(n * m * sizeof(int*));
        dynamic_third(pointer_array1, values_array, n, m);
        output(pointer_array1, n, m);
        free(values_array);
        free(pointer_array1);
    }
}

void static_matrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
}

void dynamic_first(int** a, int n, int m) {
    int* p = (int*)(a + n);
    for (int i = 0; i < n; i++)
        a[i] = p + m * i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void dynamic_second(int** a, int n, int m) {
    for (int i = 0; i < n; i++)
        a[i] = malloc(m * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
}

void dynamic_third(int** a1, int* a2, int n, int m) {
    for (int i = 0; i < n; i++)
        a1[i] = a2 + m * i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a1[i][j]);
}

int input(int* mode, int* n, int* m) {
    int flag = 0;
    char ch;
    if (scanf("%d", mode) != 1 || getchar()!= '\n' || (*mode < 1) || (*mode > 4)) { flag = 1;
    } else {
        if (scanf("%d %d", n, m) != 2) { flag = 1; }
        if ( *mode == 1 && ((*n > 100) || (*n < 1) || (*m > 100) || (*m < 1)) ) { flag = 1; }
        if ( (*mode == 2 || *mode == 3 || *mode == 4) && ((*n < 1) || (*m < 1)) )
        if (scanf("%c", &ch) == 1 && ch != '\n' && ch != '\0' && ch != EOF)
            flag = 1;
    }
    return flag;
}

void output(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1)
                printf("%d", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
        if (i != n - 1)
            printf("\n");
    }
}
