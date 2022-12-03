#include <iostream>

using namespace std;

const int N = 1000 + 10;

int val[N];
int t[N];
int f[N];

int main()
{
	int n = 0, m = 0;
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> t[i] >> val[i];
	}
	

	for (int i = m; i >= 1; --i)
	{
		for (int j = n; j >= t[i]; --j)
		{
			f[j] = max(f[j], f[j - t[i]] + val[i]);
		}
	}
	
	cout << f[n] << endl;
	
	return 0;
}
