#include <iostream>
#include <bitset>

using namespace std;

bitset<2000000 + 10> bs;

int main()
{
	int n = 0;
	
	cin >> n;
	int sum = 0;
	bs[0] = true;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		
		cin >> a;
		
		bs ^= (bs << a);
		sum += a;
	}
	int ans = 0;
	for (int i = 1; i <= sum; i++)
		if (bs[i])
			ans ^= i;
	cout << ans << endl;
	
	return 0;
}
