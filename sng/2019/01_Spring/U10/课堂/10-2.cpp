#include <bits/stdc++.h>
using namespace std;
int main()
{
	int c = 1 ,p = 1 ,t = 0;
	
	for (c = 1;c < 23;c++)
	{
		for (p = 1;p < c;p++)
		{
			t = 23 - c - p;
			if (t >= p)
			{
				continue;
			}
			
			if (c * c + p * p + t * t == 211)
			{
				cout << c << endl;
				cout << p << endl;
				cout << t << endl;
				break; 
			} 
		}
	}
	
	return 0;
}
