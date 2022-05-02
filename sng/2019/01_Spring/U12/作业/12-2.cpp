#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int a = 0 ,b = 0;
	int i = 0;
	int sum = 0 ,mul = 1;
	int num[9] = { 0 };
	
	for (a = 5123; a < 9877; a++)
	{
		b = 2 * a;
		
		num[0] = a / 1000;
		num[1] = a / 100 % 10;
		num[2] = a % 100 / 10;
		num[3] = a % 10;
		
		num[4] = b / 10000;
		num[5] = b / 1000 % 10;
		num[6] = b % 1000 / 100;
		num[7] = b % 100 / 10;
		num[8] = b % 10;
		
		sum = 0;
		mul = 1;
		
		for (i = 0; i < 9; i++)
		{
			sum = sum + num[i];
			mul = mul * num[i];
		}
		if ((45 == sum) && (362880 == mul))
		{
			cout << a << "	" << b << endl;
		}
	}
	
	return 0;
}
