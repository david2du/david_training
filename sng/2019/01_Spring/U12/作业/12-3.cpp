#include <bits/stdc++.h>
using namespace std;
int main()
{
	int age = 0 ,l = 0 ,s = 0;
	int num[10] = { 0 };
	int sum = 0 ,mul = 1 ,i = 0;
	
	for (age = 1; age < 100; age++)
	{
		l = pow(age, 3);
		s = pow(age, 4);
		if ((l < 1000) || (s < 100000))
		{
			continue;
		}
		if ((l > 9999) || (s > 999999))
		{
			break;
		}
		
		num[0] = l / 1000;
		num[1] = l / 100 % 10;
		num[2] = l % 100 / 10;
		num[3] = l % 10;
		
		num[4] = s / 100000;
		num[5] = s / 10000 % 10;
		num[6] = s % 10000 / 1000;
		num[7] = s % 1000 / 100;
		num[8] = s % 100 / 10;
		num[9] = s % 10;
		
		sum = 0;
		mul = 1;
		
		for (i = 0; i < 10; i++)
		{
			if (0 != num[i])
			{
				sum = sum + num[i];
				mul = mul * num[i];
			}
		}
		if ((45 == sum) && (362880 == mul))
		{
			cout << age << endl;
		}
	}
	
	return 0;
}
