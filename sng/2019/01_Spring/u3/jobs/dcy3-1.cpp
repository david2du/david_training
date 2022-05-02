#include<stdio.h>
int main ()
{
	int a = 0 ,b = 0 ,c = 0 ,max = 0 ,min = 0;
	
	scanf ("%d %d %d",&a ,&b ,&c );	
	
	max = a;
	min = a;
	
	if(b > max)
	{
		max = b;
	}
	if(b < min)
	{
		min = b;
	}
	if(c > max)
	{
		max = c;
	}
	if(c < min)
	{
		min = c;
	}
	printf("%d %d %d" ,max ,a + b + c - max - min ,min);
	
	return 0;
}
