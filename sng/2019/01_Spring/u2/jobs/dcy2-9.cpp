#include <iostream>
using namespace std;
int main()
{
	
int a = 0, b = 0;
	while(1)
	{
		printf("Please input two numbers:\n");
	scanf("%d , %d", &a, &b );
	if(a>b)
	{
		printf("MAX = %d\n", a);
	}
	if(a<b)
	{
		printf("MAX = %d\n", b);
	}
	if(a==b)
	{
		printf("IT IS NOT ALLOWED\n");
	}
}

    return 0;
}
