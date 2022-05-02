#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x = 0 ,y = 0;
	for (x = 1;x < 10;x++)
	{
		for (y = 0;y < 10;y++)
		{
			if (2010 -(1900 + 10 * x + y) == 1 + 9 + x + y)
			{
				cout << 1900 + 10 * x + y << endl;
				break;
			}
		}
	}
	
	return 0;
}
