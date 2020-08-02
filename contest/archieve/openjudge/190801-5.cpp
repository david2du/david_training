#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	double a[300] = {0.0};
	int i = 0, mii = 0, mai = 0;
	double min = 0.0, max = 0.0, to = 0, av = 0;
	double dif[300] = {0.0}, dmax = 0.0;
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	min = a[0];
	max = a[0];
	mii = 0;
	mai = 0;
	
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			mai = i;
		}
		if (a[i] < min)
		{
			min = a[i];
			mii = i;
		}
	}
	
	for (i = 0; i < n; i++)
	{
		if ((i != mii) && (i != mai))
		{
			to += a[i];
		}
	}
	av = to / (n - 2);
	
	for (i = 0; i < n; i++)
	{
		if ((i != mii) && (i != mai))
			dif[i] = abs(a[i] - av);
	}
	
	dmax = dif[0];
		
	for (i = 0; i < n; i++)
	{	
		if ((i != mii) && (i != mai))
		{
			if (dif[i] > dmax)
			{
				dmax = dif[i];
			}
		}
	}
	
	printf("%.2lf %.2lf", av, dmax);
	
	return 0;
}
