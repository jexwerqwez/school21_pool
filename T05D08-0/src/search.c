#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double sigma(int *a, int n);

int main() {
    int n, data[NMAX], i;
    int counter = 0;
    if (input(data, &n) != 0) {
        printf("n/a");
        return -3;
    } else {
        double math_w = mean(data, n);
        double thr_sigm = mean(data, n) + 3 * sigma(data, n);
        for (i = 0; i < n; i++) {
            if ( (data[i] % 2 == 0) && (data[i] >= math_w) && (data[i] <= thr_sigm) && (data != 0) )
                printf("%d", data[i]);
            else
                counter++;
        }
        if (counter == i)
            printf("%d", 0);
    }
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || getchar()!= '\n' || (*n < 1) || (*n > 30)) { return -1;
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

double mean(int *a, int n) {
    double sum = 0;
    int i = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum/i;
}

double sigma(int *a, int n) {
    double m = mean(a, n);
    return sqrt(m);
}
