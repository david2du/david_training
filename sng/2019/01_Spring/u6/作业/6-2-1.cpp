#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int people = 1;
	
	while (people > 0)
	{
		people++;
		if ((people % 6 != 0) || (people % 9 != 0))
		{
			continue;
		}
		if (people / 6 - 1 == people / 9 + 1)
		{
			break;
		}
	}
	cout << people << endl; 
	
	return 0;
}
