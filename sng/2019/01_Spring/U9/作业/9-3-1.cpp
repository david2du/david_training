#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0, b = 0;  
	
	for ( a = 1; ; a++)
	{
		if( 1.0/a + 1.0/(30+a) ==1.0/36)
		{ 
			break;
		}	
	}
	
	cout << "a = "<< a <<endl;
	cout <<"b = " << 30+a <<endl;
	 
	return 0;
} 
