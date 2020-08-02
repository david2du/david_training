#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 1;
	double s = 2.0, ls = 2.0, fa = 0.0, f = 0.0;
	cin >> f;
	do
	{
		fa = fa + s;		
		if (fa >= f)
		{
			cout << n << endl;
			break;
		}
		s = ls * 98.0 / 100;
		ls = s;
		n++;
	}
	while(true);
	
	return 0;
}
