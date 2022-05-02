#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	int a = 0 ,b = 0 ,c = 0 ,d = 0;
	
	cin >> n ;
	
	a = n / 1000;
	b = n % 1000 / 100 ;
	c = n % 100 / 10 ;
	d = n % 10 ;
	if ((a == d) && (b == c))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	return 0;
}
