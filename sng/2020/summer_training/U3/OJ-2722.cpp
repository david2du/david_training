#include <bits/stdc++.h>
using namespace std;

int num[128];

int main()
{
	int n = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);

	int ans = 0;
	for (int i = 2; i < n; i++) // 0 and 1 are impossible 
	{
		for (int j = 0; j < i; j++)
		{
			int idx = lower_bound(num, num + i, (num[i] - num[j])) - num;
			if ((num[idx] == (num[i] - num[j])) && (idx != j))
			{
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
