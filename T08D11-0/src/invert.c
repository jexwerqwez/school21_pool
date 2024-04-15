#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void invert(double **matrix, int n, int m);
void input(double **matrix, int n, int m);
void output(double **matrix, int n, int m);
double det(double **matrix, int n, int m);
void nominor(double **matrix, double **result, int n, int x, int y);
void transposition(double **matrix, double **result, int n);


int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || (n < 1) || (m < 1) || (m != n)) {
        printf("n/a");
        return -1;
    } else {
        double** matrix = malloc(n * sizeof(double*));
        for (int i = 0; i < n; i++) {
            matrix[i] = malloc(m * sizeof(double));
        }
        input(matrix, n, m);
        invert(matrix, n, m);
        for (int i = 0; i < n; i++)
            free(matrix[i]);
        free(matrix);
        }
    return 0;
}

void input(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lf", &matrix[i][j]);
}

void output(double **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1)
                printf("%lf", a[i][j]);
            else
                printf("%lf ", a[i][j]);
        }
        if (i != n - 1)
            printf("\n");
    }
}

void nominor(double **matrix, double **result, int n, int x, int y) {
    int off_x = 0;
    int off_y = 0;
    for (int i = 0; i < n-1; i++) {
        if (i == x)
            off_x = 1;
        off_y = 0;
        for (int j = 0; j < n-1; j++) {
            if (j == y)
                off_y = 1;
            result[i][j] = matrix[i + off_x][j + off_y];
        }
    }
}

double det(double **matrix, int n, int m) {
    int sign = 1;
    int d = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (m == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double** result = malloc(n * sizeof(double*));
        for (int i = 0; i < n - 1; i++)
            result[i] = malloc(m * sizeof(double));
        for (int j = 0; j < n; j++) {
            nominor(matrix, result, n, 0, j);
            d += sign * matrix[0][j] * det(result, n-1, m-1);
            sign = -1*sign;
        }
        for (int i = 0; i < n; i++)
            free(result[i]);
        free(result);
    }
    return d;
}

void transposition(double **matrix, double **result, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[j][i] = matrix[i][j];
}

void invert(double **matrix, int n, int m) {
    int d = det(matrix, n, m);
    double** inv_matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        inv_matrix[i] = malloc(m * sizeof(double));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double** alg_compl = malloc(n * sizeof(double*));
            for (int k = 0; k < n - 1; k++)
                alg_compl[k] = malloc(m  * sizeof(double));
            nominor(matrix, alg_compl, n, i, j);
            inv_matrix[i][j] = pow(-1.0, i + j +2) * det(alg_compl, n-1, n-1)/d;
            for (int i = 0; i < n; i++)
                free(alg_compl[i]);
            free(alg_compl);
        }
    }
    double** result = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        result[i] = malloc(m * sizeof(double));
    transposition(inv_matrix, result, n);
    output(result, n, m);
    for (int i = 0; i < n; i++)
        free(result[i]);
    free(result);
    for (int i = 0; i < n; i++)
        free(inv_matrix[i]);
    free(inv_matrix);
}
