#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[7] = {0}, b[7] = {0}, t[7] = {0};
	int i = 0, max = 0;
	
	for (i = 0; i < 7; i++)
	{
		cin >> a[i] >> b[i];
		t[i] = a[i] + b[i];
	}
	
	for (i = 0; i < 7; i++)
	{
		if (t[i] > 8)
		{
			if (t[i] > max)
			{
				max = t[i];
			}
		}
	}
	
	if (max == 0)
	{
		cout << "0" << endl;
	}
	
	for (i = 0; i < 7; i++)
	{
		if (t[i] == max)
		{
			cout << i + 1 << endl;
			break;
		}
	}
	
	return 0;
}
