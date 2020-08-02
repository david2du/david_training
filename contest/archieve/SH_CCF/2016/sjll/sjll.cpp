#include <iostream>
using namespace std;

int num[100] = {0};

int main()
{
	//freopen("sjll.in", "r", stdin);
	//freopen("sjll.out", "r", stdout);
	int x = 0, n = 0;
	int rem = 0;
	int i = 0;
	
	cin >> x >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
		rem += (x - num[i]);
	}
	
	cout << rem + x << endl;
	
	return 0;
}
