#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0;
	double b = 0.4463, c = 0.4663, d = 0.5663, t = 0;
	cin >> a;
	if (a < 151)
	{
		t = a * b;
	}
	else if ((a > 150) && (a < 401))
	{
		t = 150 * b + (a - 150) * c;
	}
	else
	{
		t = 150 * b + 250 * c + (a - 150 - 250) * d;
	}
	printf("%.1f", t);
	
	return 0;
}
