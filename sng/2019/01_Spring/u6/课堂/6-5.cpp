#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0 ,count = 0;
	cin >> n;
	while (n > 1)
	{
		if(n % 2)
		{
			n = n * 3 + 1;
		}
		else
		{
			n = n / 2;
		}
		cout << n << endl;
		count++;
	} 
	cout << "count = " << count << endl;
	
	return 0;
}
