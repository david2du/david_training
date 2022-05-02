#include <iostream>
using namespace std;
int main()
{
	
	int a = 0, b = 0,max = 0;
	while(1)
	{
		printf("Please input two numbers:\n");
	scanf("%d , %d", &a, &b );
	max = a;
	if(b>max)
	{
		printf("MAX = %d\n", a);
	}
	if(b<max)
	{
		printf("MAX = %d\n", b);
	}
	if(b==max)
	{
		printf("IT IS NOT ALLOWED\n");
	}
}
}
