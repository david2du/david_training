#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n = 0 ,x = 0;
	int a = 1 ,b = 0 ,c = 0 ,d = 0;
	for (a = 1;a < 10;a++)
	{
		for (b = 0;b < 10;b++)
		{
			for (c = 0;c < 10;c++)
			{
				for (d = 0;d < 10;d++)
				{
					n = a * 100000 + b * 10000 + b * 1000 + c * 100 + c * 10 + d;
					x = sqrt (n);
					if (n == x * x)
					{
						cout << n << endl;
						cout << endl << endl << endl;
					}
				}
			}
		}
	}
	
	return 0;
}
