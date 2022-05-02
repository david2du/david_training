#include <iostream>
using namespace std;   

int sum[4950] = {0};
int num[100] = {0};

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	int i = 0, j = 0, t = 0;
	int ans = 0;
	int n = 0;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	
	for (i = 0; i < (n - 1); i++)
	{
		for (j = (i + 1); j < n; j++)
		{
			sum[t] = num[i]+ num[j];
			t++;	
		}	
	}
	
	for (i = 0; i <= t; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (sum[i] == num[j])
			{
				ans++;
			}	
		}	
	}
	
	cout << ans <<endl;
	system("pause");
	
	return 0;
}
