#include <stdio.h>

int main()
{
	
	int a = 1, b = 2 ,c = 0;

	c = b;
	b = a;
	a = c;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}
