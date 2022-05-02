#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x = 0 ,m = 0;
	
	for (m = 1 ;m < 7; m++)
	{
		x = 303 * 70 / (56 - 10 * m);
		if (303 * 70 == (56 - 10 * m) * x)
		{
			cout << x << endl;
		} 
	}
	
	return 0;
}
