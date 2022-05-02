#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	int a = 0 ,b = 0;
	int num = 0;
	
	while (num < 10)
	{
		num++;
		a = num * 10 + 3;
		b = num + 30;
		if (a * 324 == b * 567)
		{
			cout << num << endl;
		} 	
	
	}
	
	return 0;
	
}
