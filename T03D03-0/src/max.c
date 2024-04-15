#include <stdio.h>

float com(float a, float b);  // целочисленность
int max(int a, int b);

int main()
{
    float a = 0;
    float b = 0;
    char ch;
    if( (scanf("%f %f%c", &a, &b, &ch) != 3) || (ch != '\n') ) // проверка на ввод
    {
	printf("n/a\n");
	return -1;
    }
    else
    {
	if( com(a,b) == 0 )
	{
	    printf("n/a\n");
	    return -1;
	}
	else
	    printf("%d\n", max(a,b));
    }
    return 0;
}

int max(int a, int b)
{
    if ( a > b)
	return a;
    else
	return b;
}
float com(float a, float b)
{
    if( (a == (int)a) && (b == (int)b) )
	return 1;
    else
	return 0;
}

