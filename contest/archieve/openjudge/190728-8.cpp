#include <bits/stdc++.h>//16min 41s
using namespace std;
int main()
{
	double m = 0.0;
	double r = 0.0, n = 0.0, r1 = 0.0;
	int y = 0, num = 0;
	
	cin >> r >> m >> y;
	r1 = 1 + r / 100;
	n = m;
	
	for (int i = 1; i <= y; i++)
	{
		n *= r1;
	}
	
	num = (int)n;
	cout << num << endl;
	
	return 0;
}
