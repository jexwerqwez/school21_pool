#include <stdio.h>
#include <math.h>

float compl(float x) {
    return 7e-3 * pow(x,4) + ((22.8 * pow(x,1/3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2/x) - 1.01;
}

int main()
{
    float x = 0;
    char ch;
    if( (scanf("%f%c", &x, &ch) != 2) || (ch != '\n') )
    {
	printf("n/a\n");
	return -1;
    }
    else
	printf("%.1f\n", compl(x));
    return 0;
}
