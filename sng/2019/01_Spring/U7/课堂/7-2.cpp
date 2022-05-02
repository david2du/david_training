#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int c = 1 ,r = 0;
	
	while(c < 35)
	{
		r = 35 - c;
		
		if (2 * c + 4 * r == 94)
		{
			cout << "cock :" << c << endl; 
			cout << "rabbit :" << r << endl;
			break; 
		}
		c++;
	}
	
	return 0;
} 
