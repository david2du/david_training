#include <bits/stdc++.h>
using namespace std;

int main()
{
	long num[100] = {0};
	int n = 0, i = 0;
	int max = 0;
	long long sum = 0;
	
	cin >> n;	
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
		if (num[i] > max)
		{
			max = num[i];
		}
	}
	
	for (i = 0; i < n; i++)
	{
		if (num[i] != max)
		{
			sum += num[i];
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
