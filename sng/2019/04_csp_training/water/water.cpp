#include <iostream>
#include <algorithm>
using namespace std;

int time[10000] = {0};
int sum[100] = {0};

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	int n = 0, m = 0;
	int i = 0;
	
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> time[i];
	}
	
	for (i = 0; i < m; i++)
	{
		sum[i] = time[i];
	}
	sort(sum, sum + m);
	
	for (i = m; i < n; i++)
	{
		sum[0] += time[i];
		sort(sum, sum + m);
	}
	
	cout << sum[m - 1] << endl;
	
	return 0;
}
