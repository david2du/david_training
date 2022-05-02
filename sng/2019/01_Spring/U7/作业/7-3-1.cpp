#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a = 1 ,b = 1 ,c = 0 ,step = 1;
	
	for (step = 1;step < 11;step++)
	{
		c = a + b;
		a = b;
		b = c;
		/*
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
		*/  
	}
	cout << c << endl;

	return 0;
} 
