#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int space = 0;
	int tri = 0;
	
	for (space = 1;space < 6;space++)
	{
		cout << setw(6-space);
		for (tri = 1;tri < space * 2;tri++)
		{
			cout << "$" ;
		}
		cout << endl;	
	} 
	
	return 0;
} 
