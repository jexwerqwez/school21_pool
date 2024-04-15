#include <stdio.h>
#include <math.h>

int mod(int divident, int divider);
int is_prime(int n);
int abs(int n);

int main(void) {
    int a = 0;
    int res = 0;
    char ch;
    if ( (scanf("%d%c", &a, &ch) != 2) || (ch != '\n') ) {
        printf("n/a\n");
        return -1;
    } else {
        for (int i = 1; i <= abs(a); i++) {
            if ( (mod(abs(a), i) == 0) && is_prime(i) )
                res = i;
        }
        printf("%d\n", res);
        return 0;
    }
}

int abs(int n) {
        if (n >= 0)
            return n;
        else
            return n*(-1);
}

int mod(int divident, int divider) {
    int rest = divident;
    while (1) {
        rest -= divider;
        if (rest <= 0)
            break;
    }
    return rest;
}

int is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if ( mod(n, i) == 0)
            return 0;
    }
    return 1;
}
