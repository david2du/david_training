#include <bits/stdc++.h>
using namespace std;
int main ()
{	
	int n = 0 ,time = 0;
	int a = 0 ,b = 0 ,c = 0 ;
	int newNum = 0 ,num1 = 0 ,num2 = 0;
	int max = 0 ,min = 0 ,mid = 0;
	
	cin >> n;
	newNum = n;
	
	a = newNum / 100;
	b = newNum / 10 % 10;
	c = newNum % 10;
	
	if ((a == b) || (a == c) || (b == c))
	{
		cout << "error!!!" << endl;
		return -1;	
	}
	
	else
	{
		do
		{
			a = newNum / 100;
			b = newNum / 10 % 10;
			c = newNum % 10;
			
			max = a;
			min = a;
			
			if (max < b)
			{
				max = b;
			}	
			if (max < c)
			{
				max = c;
			}
			
			if (min > b)
			{
				min = b;
			}
			if (min > c)
			{
				min = c;
			}
			mid = a + b + c - min -max;
			
			num1 = max * 100 + mid * 10 + min;
			num2 = min * 100 + mid * 10 + max;
			newNum = num1 - num2;
			
			time++;
			cout << newNum << endl; 			
		}
		while(newNum != 495);
		cout << time << endl;
	}
		
	
	
	return 0;
} 
