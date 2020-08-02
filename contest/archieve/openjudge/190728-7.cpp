#include <bits/stdc++.h>//5min 53s
using namespace std;
int main()
{
	int a[100] = {0};
	int n = 0, m = 0;
	int i = 0, num = 0;
	
	cin >> n >> m;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if (a[i] == m)
		{
			num++;
		}
	}
	
	cout << num;
	
	return 0;
}
