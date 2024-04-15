#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"


void main() {
    double *data;
    int n;
    scanf("%d", &n);
    data = (double*)malloc(sizeof(double));
    input(data, n);
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
}
