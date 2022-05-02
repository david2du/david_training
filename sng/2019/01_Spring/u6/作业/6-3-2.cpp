#include <bits/stdc++.h>
using namespace std;
int getNewNum(int num)
{
	int newNum = 0 ,a = 0 ,b = 0 ,c = 0 ,d = 0;
	int tmp = 0;
	
		a = num / 100;
		b = num / 10 % 10;
		c = num % 10;
		
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
		 		
		return newNum;
}
int main ()
{
	int n = 0;
	int num = 0 ;
	int tmp = 0 ,i = 0;
	
	cin >> n;
	num = n;
	
	do
	{
		num = getNewNum(n);
		cout << num << endl;
		n = num;
		i++;	
	}
	while (num != 208);
	
	cout << i << endl;

	return 0;
} 
