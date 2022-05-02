#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c ;
	
	if ((a + b > c)\
	  && (a + c > b)\
	  && (b + c > a))
	{
		cout << "yes" << endl; 
	}
	else
	{
		cout << "no" << endl;
	}
	
	return 0;
}
