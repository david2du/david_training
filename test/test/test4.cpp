#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a = 0 ,b = 0 ,c = 0;
	
	while(true)
	{
		cin >> a;
		system ("cls");
		
		for (b = 1;b < a + 1;b++)
		{
			srand(time(0));
			c = rand()%6 + 1;
			cout << c << endl;
		}
	}
	
	return 0;
} 
