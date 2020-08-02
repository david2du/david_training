#include <bits/stdc++.h>
using namespace std;
void swap(double &a, double &b)
{
	double n = 0;
	
	n = a;
	a = b;
	b = n;
}

int main()
{
	int n = 0, k = 0;
	int in[100] = {0}, pn[100] = {0};
	double ps[100] = {0}, is[100] = {0};
	int i = 0, a = 0, b = 0;
	
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> in[i] >> is[i];
		pn[i] = in[i];
		ps[i] = is[i]; 
	}
	
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			if (ps[a] > ps[b])
			{
				swap(ps[a], ps[b]);
				swap(pn[a], pn[b]);
			}
		}
	}
	
	printf("%d %.f",pn[n - k], ps[n - k]);
	
	return 0;
}
