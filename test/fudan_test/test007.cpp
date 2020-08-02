#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0, k = 0;
	double num = 0;
	cin >> k;
	for (n = 1; n > 0 ; n++)
	{
		num = num + 1.0 / n;
		if (num > k)
		{
			cout << n << endl;
			break;
		} 
	}
	
	return 0;
}
