#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a = 1 ,b = 1 ,c = 2 ,d = 0,i = 1;
	
	for (i = 1;i < 9;i++)
	{
		d = a + b + c;
		a = b;
		b = c;
		c = d;
		
		/*
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
		cout << "-------------------------------------"<< endl;
		cout << d << endl;
		*/  
	}
	cout << d << endl;

	return 0;
} 
