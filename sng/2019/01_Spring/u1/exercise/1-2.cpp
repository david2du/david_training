#include<stdio.h>
int main()
{
	int a = 0, b = 0;
	
	a = 3, b = 5;
	b = a + a;
	a = b + b;
	printf("a = %d , b = %d \n", a, b);
	
	getchar();
	return(0);	
}

