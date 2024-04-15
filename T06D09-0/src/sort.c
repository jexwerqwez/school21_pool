// Copyright 2022 lesleyem
#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void qsort(int *a, int left, int right);
void output(int *a, int n);

int main(void) {
    int data[NMAX];
    if (input(data, NMAX) != 0) {
        printf("n/a");
        return -1;
    } else {
        qsort(data, 0, NMAX - 1);
        output(data, NMAX);
    }
    return 0;
}

int input(int *a, int n) {
    for (int* p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) { return -1; }
    }
    return 0;
}

void qsort(int *a, int l, int r) {
    int l_board = l;
    int r_board = r;
    int piv = a[l];
    while ( l < r ) {
        while ( (a[r] >= piv) && (l < r) ) { r--; }
            if (l != r) {
                a[l] = a[r];
                l++;
            }
        while ( (a[l] <= piv) && (l < r) ) {l++;}
        if (l != r) {
            a[r] = a[l];
            r--;
        }
    }
    a[l] = piv;
    piv = l;
    l = l_board;
    r = r_board;
    if (l < piv)
        qsort(a, l, piv - 1);
    if (r > piv)
        qsort(a, piv + 1, r);
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0 )
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}
