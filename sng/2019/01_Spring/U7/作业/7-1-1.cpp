#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int x = 0;
	
	for (x = 0;x < 680 /4 + 1;x++)
	{
		if (4 * x + (x + 40) * 8 == 680)
		{
			cout << "4 yuan :" << x << endl << "8 yuan :" << x + 40 << endl;
			break; 
		}
	}

	return 0;
} 
