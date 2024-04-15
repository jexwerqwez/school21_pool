#include <stdio.h>
#define NMAX 10


int input(int *a, int *n, int *c);
void shifting(int *a, int n, int shift);
void output(int *a, int n);

int main(void) {
    int n, data[NMAX], c;
    if (input(data, &n, &c) != 0) {
        printf("n/a");
        return -1;
    } else {
        shifting(data, n, c);
        output(data, n);
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0 )
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
    printf("\n");
}

int input(int *a, int *n, int *c) {
    if (scanf("%d", n) != 1 || getchar()!= '\n' || (*n < 1) || (*n > 10)) { return -1;
    } else {
        for (int* p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) { return -2; }
        }
    }
    if (scanf("%d", c) != 1 || getchar() != '\n') { return -3;}
    return 0;
}

void shifting(int *a, int n, int shift) {
    int elem = 0;
    if (shift > 0) {
        elem = shift;
    } else {
        elem = n + shift % n;
    }
    for (int i = 0; i < elem; ++i) {
        int tmp = a[0];
        for (int i = 1; i < n; ++i)
            a[i-1] = a[i];
        a[n-1] = tmp;
    }
}
