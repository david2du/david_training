#include<stdio.h>
int main()
{
	int a = 1;
	
	a = a + a;
	a = a * a * a * a * a * a * a * a \
			+ a * a * a * a * a * a \
			+ a * a * a * a * a \
			+ a * a * a \ 
			+ a * a \
			+ a / a;
	printf("a = %d\n", a);
	
	getchar();	
	return(0);	
}

