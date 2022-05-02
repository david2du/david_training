#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int x = 0;
	
	for (x = 0;true;x++)
	{
		if (4 * 7 * x - 4 * 5 * (13 + x) == 20)
		{
			cout << "7 :" << x << endl << "5 :" << x + 13 << endl;
			break; 
		}
	}

	return 0;
} 
