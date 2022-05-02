#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num1 = 0 ,num2 = 0 ,num3 = 0 ,n = 0 ;
	int a = 0 ,b = 0 ,c = 0 ;
	int d = 0 ,e = 0 ,f = 0 ;
	int g = 0 ,h = 0 ,i = 0 ;
	
	n = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
	for (num1 = 123; num1 < 987 / 3; num1++)
	{
		num2 = 2 * num1;
		num3 = 3 * num1;
		a = num1 / 100;
		b = num1 / 10 % 10;
		c = num1 % 10;
		
		d = num2 / 100;
		e = num2 / 10 % 10;
		f = num2 % 10;
		
		g = num3 / 100;
		h = num3 / 10 % 10;
		i = num3 % 10;
		
		if ((a + b + c\
		+ d + e + f\
		+ g + h + i == 45)\
		&& (a * b * c\
		* d * e * f\
		* g * h * i == n))
		{
			cout << num1 << "," << num2 << "," << num3 << endl;
			cout << "----------------------" << endl;
		}				
	}
	
	return 0;
}
