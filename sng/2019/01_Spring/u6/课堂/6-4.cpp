#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i = 0 ,sum = 0 ,p = 0;
	int num = 1;
	
	p = 9 + 6;
	while (i < 10)
	{
		sum = sum + i;
		i++;  
	}
	num = sum / p;
	cout << num; 
	
	return 0;
}
