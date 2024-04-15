#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void qsort(int *a, int left, int right);
void output(int *a, int n);
void shiftdown(int *a, int n, int i);
void hsort(int *a, int n);
void copy(int *a1, int *a2, int n);

int main(void) {
    int data1[NMAX], data2[NMAX];
    if (input(data1, NMAX) != 0) {
        printf("n/a");
        return -1;
    } else {
        copy(data1, data2, NMAX);
        qsort(data1, 0, NMAX - 1);
        output(data1, NMAX);
        printf("\n");
        hsort(data2, NMAX);
        output(data2, NMAX);
    }
    return 0;
}

int input(int *a, int n) {
    for (int* p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) { return -1; }
    }
    return 0;
}

void copy(int *a1, int *a2, int n) {
    while (n--) {
        *a2++ = *a1++;
    }
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

void shiftdown(int *a, int n, int i) {
    int child = i;
    int left = 2*i + 1;
    int right = 2*i +2;
    if (left < n && a[left] > a[child])
        child = left;
    if (right < n && a[right] > a[child])
        child = right;
    if (child != i) {
        int tmp = a[i];
        a[i] = a[child];
        a[child] = tmp;
        shiftdown(a, n, child);
    }
}

void hsort(int *a, int n) {
    for (int i = n/2-1; i >= 0; i--)
        shiftdown(a, n , i);
    for (int i = n - 1; i>= 0; i--) {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        shiftdown(a, i, 0);
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0 )
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}
