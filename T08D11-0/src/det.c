#include <stdio.h>
#include <stdlib.h>

void input(double **matrix, int n, int m);
void output(double det);
double det(double **matrix, int n, int m);
void nominor(double **matrix, double **result, int n, int x, int y);

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || (n < 1) || (m < 1) || (m != n)) {
        printf("n/a");
        return -1;
    } else {
        double **matrix = malloc(n * sizeof(double*));
        input(matrix, n, m);
        output(det(matrix, n, m));
        for (int i = 0; i < n; i++)
            free(matrix[i]);
        free(matrix);
    }
    return 0;
}

void input(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++)
        matrix[i] = malloc(m * sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lf", &matrix[i][j]);
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
        double** result = malloc( (n - 1) * sizeof(double*));
        for (int i = 0; i < n - 1; i++)
            result[i] = malloc( (m - 1) * sizeof(double));
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

void output(double det) {
    printf("%.6f", det);
}
