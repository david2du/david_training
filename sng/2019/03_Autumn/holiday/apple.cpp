#include <bits/stdc++.h>
using namespace std;

int main()
{
	int apl[50] = {0}; //apple
	int n = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> apl[i];
	}

	int lftn = n, ans = 0; //left_number, answer

	lftn = n;
	while (lftn > 1)
	{
		int bgn = n - lftn; //begin

		sort(apl + bgn, apl + n);

		int num = apl[bgn] + apl[++bgn];

		ans += num;
		apl[bgn] = num;

		lftn--;
	}

	cout << ans << endl;

	return 0;
}