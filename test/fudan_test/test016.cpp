#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int main()
{
	bool f = false;
	int n = 0, i = 0, j = 0;
	float temp = 0.0, a[MAXN] = {0.0};
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	 
	for (i = n - 1; i > 0; i--)
	{
		f = true;
		
		for (j = 1; j < i + 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				f = false;
			}
		}
		if (f == false)
		{
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	
	return 0;
} 
