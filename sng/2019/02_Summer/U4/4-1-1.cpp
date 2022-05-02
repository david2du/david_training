#include <bits/stdc++.h>
using namespace std;
int a = 3, b = 5;
int max(int a, int b)
{
	int c = 0;
	c = a > b ? a : b;
	printf("a = %d b = %d", a, b);
	
	return c;
}

int main()
{
	int a = 8;
	
	printf("%d", max(a, b));
	
	return 0;
}
