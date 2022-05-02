#include <bits/stdc++.h>
using namespace std;
int getNumber (int num)
{
	int n = 0 ,m = 0;
	n = num;
	for (;n > 0;)
	{
		m = m * 10 +n % 10;
		n = n / 10;
	} 
	return m;
}
int main ()
{
	int num = 0 ,n = 0;
	cin >> num;
		
	n= getNumber(num);
	
	if(n == num)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
		 
	return 0;
}
