#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n[12] = {0}, l[12] = {0}, gm[12] = {0};
	int m = 0, lto = 0, i = 0;
	int sum = 0;
	bool g[12] = {0};
	
	for (i = 0; i < 12; i++)
	{
		cin >> n[i];
		
		if ((300 - n[i]) > 99)
		{
			g[i] = true;
			gm[i] = (300 - n[i]) / 100;
			l[i] = (300 - n[i]) % 100;
		}
	}
	
	for (i = 0; i < 12; i++)
	{
		lto += l[i];
		if (lto > 100)
		{
			gm[i] += lto / 100;
		}
	}
	
	for (i = 0; i < 12; i++)
	{
		m += gm[i];		
		lto += l[i]; 
		if((lto + 300) < n[i])
		{
			cout << "-" << i + 1 << endl;
			return 0;
		}
	}
	
	for (i = 0; i < 12; i++)
	{
		lto += l[i]; 
		m += gm[i];	 
	}
	
	sum = lto + (m + m / 5);
	
	cout << sum << endl;
	
	return 0;
} 
