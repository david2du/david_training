#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool a[10001] = {false};
	int l = 0, m = 0, i1 = 0, i2 = 0, num = 0;
	int s[100] = {0}, e[100] = {0};
	
	cin >> l >> m;
	for (i1 = 0; i1 < m; i1++)
	{
		cin >> s[i1] >> e[i1];
	}
	
	for (i1 = 0; i1 < l + 1; i1++)
	{
		a[i1] = true;
	}
	for (i1 = 0; i1 < m; i1++)
	{
		for (i2 = s[i1]; i2 < e[i1] + 1; i2++)
		{
			a[i2] = false;
		}
	}
	
	for (i1 = 0; i1 < 10001; i1++)
	{
		if (a[i1] == true)
		{
			num++;
		}
	}
	cout << num << endl;
	
	return 0;
}
