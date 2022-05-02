#include<stdio.h>
int main ()
{
	int a = 0;
	scanf ("%d",&a);
	printf("%d\n", a);	
	if(a < 10)
	{
		printf("%d is less than 10.\n" ,a);
	}
	if((a >= 10)&&(a <= 99))
	{
		printf("%d is 10 to 99.\n" ,a);
	}
	if((a >= 100)&&(a <= 999))
	{
		printf("%d is 100 to 999.\n" ,a);
	}
	if(a >= 1000)
	{
	printf("%d is bigger than 999.\n" ,a);
	}
	return 0;
}
