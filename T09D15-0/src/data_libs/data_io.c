#include "data_io.h"
#include <stdio.h>

void input(double *data, int n) {
    for (double* p = data; p - data < n; p++) {
        scanf("%lf", p);
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0 )
            printf("%.2lf", data[i]);
        else
            printf(" %.2lf", data[i]);
    }
}
