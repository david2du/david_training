#include <stdio.h>

int main()
{
	int a = 0 ,b = 0;
	printf("Please input the score:\n");
	scanf("%d%d", &a, &b) ;
	
	
	if( (a < 60) && (b >= 60) )
	{
		printf("1\n");
	}
	
	else if( (a >= 60) && (b < 60) )
	{
		printf( "1\n");
	}
	
	else
	{
		printf("0\n") ;
	}
	
	return 0;
}
