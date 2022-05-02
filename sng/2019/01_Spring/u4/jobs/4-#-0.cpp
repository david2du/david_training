#include <bits/stdc++.h>
using namespace std;

int prime(int n)
{
	int r = sqrt(n);
	for(int i = 2;i <= r;i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int a = 0 ,b = 0;
	cin >> a;
	b = prime(a);
	if (b == 1)
	{
		cout << a << " is a prime" << endl ;
	}
	else
	{
		cout << a << " isn't prime" << endl ;
	}
}
