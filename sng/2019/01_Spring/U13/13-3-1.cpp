#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0 ,m = 0 ,k = 1;
	bool found = false;
	
	while(!found)
	{
		m = 7 * k + 1;
		for (n = 1; n < m + 1; n++)
		{
			if ((n * (n - 1) / 2 ) * (1 + (m - 1) / 7) == (m - n))
			{
				cout << "n : " << n << endl;
				cout << "m : " << m << endl;
				found = true;
				break; 
			}  
		}
		k++;
	}
	
	return 0;
}
