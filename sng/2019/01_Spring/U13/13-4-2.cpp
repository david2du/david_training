#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a5 = 3 ,a4 = 0 ,a3 = 0 ,a2 = 0 ,a1 = 0, a0;
	
	for (;true;a5 += 4)
	{
		a4 = 5 * a5 / 4 + 1;
		if (a4 % 4 != 0)
		{
			continue;
		}
		
		a3 = 5 * a4 / 4 + 1;
		if (a3 % 4 != 0)
		{
			continue;
		}
		
		a2 = 5 * a3 / 4 + 1;
		if (a2 % 4 != 0)
		{
			continue;
		}
		
		a1 = 5 * a2 / 4 + 1;
		if (a1 % 4 != 0)
		{
			continue;
		}
		
		a0 = 5 * a1 / 4 + 1;
		if (a0 % 4 != 0)
		{
			continue;
		}
		/*
		cout << a5 << endl;
		cout << a4 << endl;
		cout << a3 << endl;
		cout << a2 << endl;
		*/
		cout << a0 << endl;
		break;
	}	
	
	return 0;
}
