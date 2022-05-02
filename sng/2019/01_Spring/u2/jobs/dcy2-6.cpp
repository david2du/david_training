#include <stdio.h>

int main()
{
	
	int a = 1, b = 2 ,c = 3 , d = 4 , e = 0;
	e = b;
	b = c;
	c = e;
	
	e = a;
	a = d;
	d = e; 

	
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    
    return 0;
}
