#include <iostream>
#include <algorithm>
using namespace std;

int time[10001] = {0};

int main()
{
	int m = 0, n = 0;
	int q = 0, i = 0, j = 0;
	int sum = 0;
	
	cin >> n >> m;
	for (i = 1; i < n; i++)
	{
		cin >> time[i];
	}
	sort(time + 1, time + n + 1);
	
	for (i = 1; i < n; i++)
	{
		if (i % m == 0)
		{
			sum += time[i];
		}
	}
	cout << sum << endl;
	
	return 0;
}
