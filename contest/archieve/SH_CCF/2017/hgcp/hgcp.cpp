#include <iostream>
using namespace std;

int w[10000] = {0};

int main()
{
	freopen("hgcp.in", "r", stdin);
	freopen("hgcp.out", "w", stdout);
	
	int n = 0, g = 0;
	int sum = 0, num = 0;
	int i = 0;
	
	cin >> n >> g;
	for (i = 0; i < n; i++)
	{
		cin >> w[i];
		if (w[i] > g)
		{
			num++;
			sum += w[i];
		}
	}
	cout << num << endl << sum << endl;
	
	return 0;
}
