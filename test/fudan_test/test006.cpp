#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0;
	int d = 0, e = 0, f = 0;
	int g = 0, h = 0, i = 0;
	int j = 0, k = 0, l = 0; 
	for (a = 123; a < 330; a++)
	{
		b = 2 * a;
		c = 3 * a;
		
		d = a / 100;
		e = a / 10 % 10;
		f = a % 10;
		
		g = b / 100;
		h = b / 10 % 10;
		i = b % 10;
		
		j = c / 100;
		k = c / 10 % 10;
		l = c % 10;
		
		if ((d + e + f + g + h + i + j + k + l == 45) && \
		(d * e * f * g * h * i * j * k * l == 362880))
		{
			cout << a << " " << b << " " << c << endl;
		}
	}
	
	return 0;
 } 
