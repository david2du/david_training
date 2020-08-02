#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	int e = 0 ,f = 0, m = 0;
	cin >> a >> b >> c >> d;
	m = 60 * (c - a) + d - b;
	e = m / 60;
	f = m % 60;
	cout << e << " " << f << endl;
	
	return 0;
}
