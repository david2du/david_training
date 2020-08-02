#include <iostream>
using namespace std;

int main()
{
	freopen("qy.in", "r", stdin);
	freopen("qy.out", "w", stdout);
	
	int num[10] = {0};
	int n = 0, sum = 0;
	int i = 0;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
		num[i] += 2;
		sum += num[i];
	}
	
	if (sum % 36 != 0)
	{
		cout << sum / 36 + 1 << endl;
	}
	else
	{
		cout << sum / 36 << endl;
	}
	
	return 0;
}
