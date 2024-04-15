#include "data_stat.h"

double max(double *data, int n) {
    double max_ = data[0];
    for (int i = 0; i < n; i++)
        if (data[i] > max_)
            max_ = data[i];
    return max_;
}
double min(double *data, int n) {
    double min_ = data[0];
    for (int i = 0; i < n; i++)
        if (data[i] < min_)
            min_ = data[i];
    return min_;
}
double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += data[i];
    return sum/n;
}
double variance(double *data, int n) {
    double m = mean(data, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (data[i] - m) * (data[i] - m);
    }
    return sum/(double)n;
}
