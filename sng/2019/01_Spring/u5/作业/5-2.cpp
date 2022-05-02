#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0 ,b = 0 ,c = 0;
	int num = 0;
	
	for (num = 100;num < 1000;num++)
	{
		a = num / 100;
		b = num / 10 % 10;
		c = num % 10;
		
		if (num == (pow(a ,3) + pow(b ,3) + pow(c ,3)))
		{
			cout << num << endl;
		} 	
	}
	return 0;
}
