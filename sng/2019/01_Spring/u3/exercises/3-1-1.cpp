#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	
	if (a + b <= c)
	{
		cout << "no" << endl ;
	} 
	else if (a + c <= b)
	{
		cout << "no" << endl ;
	}
	else if (b + c <= a)
	{
		cout << "no" << endl ;
	}
	else 
	{
		cout << "yes" << endl ;
	}
	
	return 0; 
}
