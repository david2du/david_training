#include <bits/stdc++.h>

using namespace std;

int f[1000 + 10]; 

int main()
{
	int h1 = 0, h2 = 0;
	int m1 = 0, m2 = 0;
	
	scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
	
	int t = (h2 - h1) * 60 + m2 - m1;
	int n = 0;
//	cout << t << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		
		if (c == 0)
		{
			for (int j = a; j <= t; j++)
				f[j] = max(f[j], f[j - a] + b);
		}
		else if (c == 1)
		{
			for (int j = t; j >= a; j--)
				f[j] = max(f[j], f[j - a] + b);
		}
		else
		{
			for (int cnt = 1; c > 0; c -= cnt, cnt <<= 1)
			{
				int d = min(cnt, c);
				for (int j = t; j >= a * d; j--)
					f[j] = max(f[j], f[j - a * d] + b * d);
			}
		}
	}
	cout << f[t] << endl;
	
	return 0;
}
