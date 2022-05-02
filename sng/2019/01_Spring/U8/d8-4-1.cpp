#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int row = 0 ,wid = 1;
	char n = 31;
	for (row = 1;row < 6;row++)
	{
		for(wid = 1;wid < row + 1;wid++)
		{
			system("color 2");
			cout << n;
		}
		cout << endl;
	}
	
	return 0;
} 
