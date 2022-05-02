#include <bits/stdc++.h>
using namespace std;
int x,y;
void sub(int y)
{ int x = 0;
	x = 22;
	x = x + y;	
	printf("x in sub: %d\n",x);
	printf("y in sub: %d\n",y);
}

int main()
{
	x = 11;
	y = 11;
    printf("x in main: %d\n",x);
    printf("y in main: %d\n",y);
    sub(y);
    printf("x in main: %d\n",x);
	printf("y in main: %d\n",y);
    getchar(); 

	return 0;    
} 

