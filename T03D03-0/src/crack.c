#include <stdio.h>

int main()
{
    float a = 0;
    float b = 0;
    char ch;
    if( (scanf("%f %f%c", &a, &b, &ch) != 3) || ( ch != '\n') ) {
        printf("n/a\n");
        return -1;
    } else
    {
	if( (a*a + b*b) < 25 )
	    printf("GOTCHA\n");
	else
	    printf("MISS\n");    
    }
    return 0;
}
