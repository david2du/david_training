#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num = 0;
	for (num = 1; true; num++)
	{
		if ((num % 4 == 1) \
		&& (num % 5 == 1) \
		&& (num % 6 == 1) \
		&& (num % 7 == 0))
		{
			cout << num << endl;
			break;
		}
	}
	
	return 0;
}
