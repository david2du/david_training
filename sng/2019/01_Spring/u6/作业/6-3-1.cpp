#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n = 0;
	int newNum = 0 ,a = 0 ,b = 0 ,c = 0 ,d = 0;
	int tmp = 0 ,i = 0;
	
	cin >> n;
	newNum = n;
	
	do
	{
		a = newNum / 100;
		b = newNum / 10 % 10;
		c = newNum % 10;
		
		d = b + c;
		if(d >= 10)
		{
			d = d / 10 + d % 10;
		}
		
		tmp = (a + b + c) * 2;
		if (tmp < 10)
		{
			tmp = tmp * 10;
		}
		tmp = tmp * 10 + d;
		
		newNum = tmp;
		
		i++;
		cout << newNum << endl; 		
	}
	while (newNum != 208);
	cout << i << endl;

	return 0;
} 
