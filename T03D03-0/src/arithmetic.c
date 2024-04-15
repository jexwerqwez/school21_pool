#include <stdio.h>

float com(float a, float b);  // целочисленность
int sum(int a, int b);  // сумма
int dif(int a, int b);  // разность
int pro(int a, int b);  // произведение
int quo(int a, int b);  // частное

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
    	if ( com(a,b) == 0)
    	{
	    printf("n/a\n");
	    return -1;
	}
	else
	{
	    if (b == 0)
		printf("%d %d %d %s\n", sum(a,b), dif(a,b), pro(a,b), "n/a");
	    else
		printf("%d %d %d %d\n", sum(a,b), dif(a,b), pro(a,b), quo(a,b));
	    return 0;
	}
     }
}

int sum(int a, int b){
    return a+b;
}
int dif(int a, int b) {
    return a-b;
}
int pro(int a, int b) {
    return a*b;
}
int quo(int a, int b) {
	return a/b;
}

float com(float a, float b)
{
    if( (a == (int)a) && (b == (int)b) )
	return 1;
    else
	return 0;
}
