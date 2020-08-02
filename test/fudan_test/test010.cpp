#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10] = {0}, h = 0, i = 0, n = 0;
	
	for ( i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	cin >> h;
	
	for (i = 0; i < 10; i++)
	{
		if (h + 30 >= a[i])
		{
			n++;
			//cout << i << endl;
		}
	}
	cout << n;
	
	return 0;
}
