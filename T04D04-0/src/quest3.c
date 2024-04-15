#include <stdio.h>

int fib(int n);

int main() {
    int n = 0;
    char ch;
    if (scanf("%d%c", &n, &ch) != 2 || ch != '\n') {
        printf("n/a\n");
        return -1;
    } else {
        printf("%d\n", fib(n));
    }
    return 0;
}

int fib(int n) {
    if ( n <= 0)
        return 0;
    else if ( (n == 1) || (n == 2) )
        return 1;
    else
        return fib(n-1) + fib(n-2);
}
