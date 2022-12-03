#include <iostream>
#include <bitset>

using namespace std;

bitset<2000000 > a;
int sum,n,ans;
// int x;
int main()
{
	
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		cerr<<x<<endl;
		
		a ^= (a << x);
		sum += x;
	}
	for (int i = 1; i <= sum; i++)
		if (a[i])
			ans ^= i;
	printf("%d", ans) ;
	
	return 0;
}
