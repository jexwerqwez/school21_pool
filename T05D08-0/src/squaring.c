#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a");
        return -3;
    } else {
        squaring(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || (*n < 1) || (*n > 10) || getchar() != '\n') { return -1;
    } else {
        for (int* p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) { return -2; }
        }
    }
    char ch;
    if (scanf("%c", &ch) == 1 && ch != '\n' && ch != '\0' && ch != EOF)
        return -3;
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0 )
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
