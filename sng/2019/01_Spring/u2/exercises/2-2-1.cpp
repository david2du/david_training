#include<stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	int tmp = 0;
	
	scanf("a=%d,b=%d,c=%d" , &a, &b, &c);
	
	if(a < b)
	{
		tmp = b;
		b = a;
		a = tmp;	
	}
	if(a < c)
	{
		tmp = c;
		c = a;
		a = tmp;
	}
	 
	if(b < c)
	{
		tmp = c;
		c = b;
		b = tmp;	
	}
	printf("a=%d b=%d c=%d" , a, b, c);
	return 0;
}
