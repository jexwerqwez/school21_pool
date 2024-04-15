#include <stdio.h>
#include <math.h>
#define PI -3.14159265358979323846

double Verziera(double x);
double Lemniscate(double x);
double Hyperbola(double x);

int main(void) {
    double step = (-2 * PI) / 41;
    double x = PI;
    for (int i = 0; i < 42; i++) {
        if (Lemniscate(x) < 0)
            printf("%.7lf | %.7f | - | %.7lf\n", x, Verziera(x), Hyperbola(x));
        else
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", x, Verziera(x), Lemniscate(x), Hyperbola(x));
        x += step;
    }
    return 0;
}

double Verziera(double x) {
    return pow(1, 3) / ( pow(1, 2) + pow (x, 2) );
}

double Lemniscate(double x) {
    double domain = sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2);
    if (domain < 0) {
        return -1;
    } else {
            return sqrt( domain );
    }
}

double Hyperbola(double x) {
    return 1 / pow(x, 2);
}
