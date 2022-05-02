#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s = 0 ,speed = 0;
	int a = 0 ,b = 0 ,c = 0 ,d = 0;
	for (s = 15952; s < 15952 + 2 * 80 + 1; s++)
	{
		a = s / 10000;
		b = s / 1000 % 10;
		c = s % 100 / 10;
		d = s % 10;
		if ((a == d) && (b == c))
		{
			speed = (s - 15951) / 2;
			cout << speed << "km / h" << endl;
		}	 
	}
	
	return 0;
}
