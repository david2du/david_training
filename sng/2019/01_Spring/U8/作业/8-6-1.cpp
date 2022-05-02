#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i = 0; 
	int j = 0; 
	int count  = 0;
	
	for (i = 1 ; i < 6; i++)
	{
		for(j = 1; j < 6-i; j++)
		{
			cout <<" ";
		}
		;
		for (count = 1; count < 2 * i; count ++)
		{
			cout << "*"; 
		}
		cout <<endl;
		
	}
	
}
