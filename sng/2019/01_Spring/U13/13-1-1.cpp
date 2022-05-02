#include <bits/stdc++.h>
using namespace std;
int main()
{
	int high = 468 ,h = 0;
	int p = 0 ,num = 0;
	
	h = 468 * 1000 * 10;
	while(true)
	{
		num = pow(2 ,p);
		if (num > h)
		{
			break;
		}
		p++;	
	}
	cout << p << endl;
	
	return 0;
}
