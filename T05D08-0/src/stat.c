#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) < 0) {
        printf("n/a");
        return -1;
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || getchar()!= '\n' || (*n < 1) || (*n > 10)) { return -1;
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
    printf("\n");
}

int max(int *a, int n) {
    int max = -2147483647;
    for (int i = 0; i < n; i++) {
        if ( a[i] > max )
            max = a[i];
    }
    return max;
}

int min(int *a, int n) {
    int min = 2147483647;
    for (int i = 0; i < n; i++) {
        if ( a[i] < min )
            min = a[i];
    }
    return min;
}

double mean(int *a, int n) {
    double sum = 0;
    int i = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum/i;
}

double variance(int *a, int n) {
    double m = mean(a, n);
    double sum = 0;
    double srq[NMAX];
    int i = 0;
    for (i = 0; i < n; i++) {
        srq[i] = (a[i] - m) * (a[i] - m);
        sum += srq[i];
    }
    return sum/((double)i);
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
