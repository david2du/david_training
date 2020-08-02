#include <iostream>
#include <algorithm>
using namespace std;

int num[1000] = {0};

int main()
{
	freopen("zjs.in", "r", stdin);
	freopen("zjs.out", "w", stdout);
	
	int n = 0;
	int i = 0;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	
	sort(num, num + n);
	
	if (n % 2 == 0)
	{
		cout << num[n / 2] << endl;
	}
	else
	{
		cout << num[(n + 1) / 2 - 1] << endl;
	}
	
	return 0;
}
