#include <stdio.h>

int main()
{
	
	int a = 12, b = 13 ,c = 11 , d = 0;
	d = a;
	a = c;
	c = b;
	b = d;
	
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    return 0;
}
