#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n = 0;
	for (n = 1;n < 105;n++)
	{
		if ((n % 3 == 2) && (n % 5 == 3) && (n % 7 == 2))
		{
			cout << n << endl ; 
		}
		else
		{
			continue;
		}
	}
		 
	return 0;
}
