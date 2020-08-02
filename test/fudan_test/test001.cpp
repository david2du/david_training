#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0 ,x = 0;
	int sum = 0 ,count = 0 ,s = 0;
	int num = 0 ,i = 0 ;
	
	cin >> n;
	num = n;
	
	for (x = 1;x < n; x++)
	{
			for (count = 1; count < 3; count++)
			{
				i = num % 10;
				num = num / 10;
				if (i != 7)
				{
					s = x * x;
					sum = sum + s;
					continue;
				}
				if (x % 7 != 0)
				{
					s = x * x;
					sum = sum + s; 
				} 
			}
	}
	cout << sum << endl;
	
	return 0;
}

