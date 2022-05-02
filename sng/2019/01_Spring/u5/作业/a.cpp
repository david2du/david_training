#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
	int i = 0; 
	int sum = 0;
	for (i = 1 ; i< 18; i++)
	{
		sum = sum + pow(2*i-1,2);
	}
	
	cout << sum;

}
