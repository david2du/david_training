#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int all = 0, b = 0;
	bool found = false;
	
	do
	{
		all += 35;
		for (b = 1; b < 7; b++)
		{
			if (all == (all / 5 + all * b / 7 + 303))
			{
				cout << all << endl;
				found = true;
				break;
			}
		}
	}
	while(!found);
	
	return 0;
}
