#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	do
	{
		if ((100 * n + 1021 + 10 * n )== 2011)
		{
			cout << n << endl;
		}
		n++;
	}
	while (n < 10);
	return 0;
} 
