#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int p = 1 ,m = 0 ,l = 0;
	for (p = 1;true;p++)
	{
		l = 3 + p - 1;
		m = (3 + l) * p / 2;
		if (100 * p == m)
		{
			cout << p << endl;
			break;
		}	
	}
	
	return 0;
}
