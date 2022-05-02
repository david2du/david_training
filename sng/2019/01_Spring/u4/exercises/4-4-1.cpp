#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	int a = 0 ,b = 0 ,c = 0 ,d = 0 ,e = 0;
	int m = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	
	cin >> n ;
	
	a = n / 1000;
	b = n / 100 % 10;
	c = n % 100 / 10;
	d = n % 10;
	
	m = 1000 * d + 100 * c + 10 * b + a;
	
	x = m + n;
	
	a = x / 10000;
	b = x / 1000 % 10;
	c = x % 1000 / 100;
	d = x % 100 / 10;
	e = x % 10;
	
	y = 10000 * e + 1000 * d + 100 * c + 10 * b + a;
	
	z = x + y;
	
	a = z / 10000;
	b = z / 1000 % 10;
	c = z % 1000 / 100;
	d = z % 100 % 10;
	e = z % 10;
	
	if((a == e) && (b == d))
	{
		cout << "yes" << endl;
	} 
	else
	{
		cout << "no" << endl;
	}
	
	return 0;
}
