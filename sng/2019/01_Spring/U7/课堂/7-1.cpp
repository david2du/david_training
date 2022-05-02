#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int c = 0 ,r = 0;
	
	for(c = 1;c < 35;c++)
	{
		r = 35 - c;
		
		if (2 * c + 4 * r == 94)
		{
			cout << "cock :" << c << endl; 
			cout << "rabbit :" << r << endl;
			break; 
		}
	}
	
	return 0;
} 
