#include <stdio.h>
int main()
{
	int n = 0, x = 0, y = 0;
	int q = 0, r = 0;
	int sum = 0;
	
	/*
	n = 10;
	x = 4;
	y = 9;
	*/
	scanf ("%d %d %d", &n, &x, &y);
	q = y / x;
	r = y % x;
	
	if( r == 0)
	{
		sum = n - q;
	} 
	else
	{
		sum = n - q - 1;
	}
	printf("%d\n", sum);
	  
	return 0;
}
