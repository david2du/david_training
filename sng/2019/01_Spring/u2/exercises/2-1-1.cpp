#include<stdio.h>

int main()
{
	int a = 0, b = 0,c = 0;
	scanf("%d%d%d", &a, &b, &c);
	
	if(((c > a) && (a > b)) || ((b > a) && (a > c))) 
	{
		printf(" a = %d \n" , a );
	}
	if(((a > b) && (b > c)) || ((c > b) && (b > a))) 
	{
		printf(" b = %d \n" , b );
	}
	if(((a > c) && (c > b)) || ((b > c) && (c > a))) 
	{
		printf(" c = %d \n" , c );
	}
	
	return 0;
}
