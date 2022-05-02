#include<stdio.h>
int main()
{
	int a = 6;
	int x = 0;
	
	x = a + a + a + a;
	printf("x=%d\n", x);
	
	printf("%d+%d+%d+%d = %d\n", a, a, a, a, x);
	
	return (0);
}
