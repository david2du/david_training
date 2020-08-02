#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a = 0, b = 0, c = 0, d = 0;
	while(1)
	{
		cin >> a >> b >> c ;
		
		d = a + b;
		if(d == c)
		{
			cout << "you are right!" << "the sum is " << d << endl ;
		}  
		else
		{
			cout << "you are so silly!!" << "the true sum is " << d << endl ;
		}	
	}
	  
	
	return 0;
}
