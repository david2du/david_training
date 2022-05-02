#include <bits/stdc++.h>
using namespace std;
int getNum(int num)
{
	int a = 0 ,b = 0 ,c = 0 ,d = 0 ,e = 0;
	int m = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	
	a = num / 10000;
	b = num / 1000 % 10;
	c = num % 1000 / 100;
	d = num % 100 / 10;
	e = num % 10;
	
	m = 10000 * e + 1000 * d + 100 * c + 10 * b + a;
	
	x = m + num;
}
int main ()
{
	int a = 0;
	int b = 0;
	cin >> a ;
	b = getNum(a);
	cout << b << endl;
	return 0;
}
