#include <stdio.h>
int main()
{
	int name;
	char ch;
	if( (scanf("%d%c", &name, &ch) != 2) || (ch != '\n') )
	{
		printf("n/a\n");
		return -1;
	}
	else printf("Hello, %d!\n", name);
	return 0;
}
