#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i = 0; 
	int j = 0; 
	int count  = 0;
	int n = 0;
 
	
	
	for (i = 1 ; i < 10; i++)
	{
		if (i < 6)
		{
			for(j = 1; j < 6-i; j++)
			{
				cout <<" ";
			}
		
			for (count = 1; count < 2 * i; count ++)
			{
				cout << "*";
			}
			cout <<endl;
			
		}
		else
		{
			n = i - 5; 
			for(j = 1; j < n + 1; j++)
			{
				cout <<" ";
			}
		
			for (count = 1; count < 9 - 2 * n + 1; count ++)
			{
				cout << "*"; 
			}
			cout <<endl;
			
		}
		
		
		
		
	}
	
}
