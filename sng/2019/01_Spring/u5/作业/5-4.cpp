#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long i = 0 ,a = 0;
	unsigned long long sum = 0;
	
	cin >> a;
	if(a > 63)
	{
		system("cls");
		cout << "TOO BIG !ERROR!!!" << endl;
		return 1;
	}
	
	for (i = 1;i < a + 1;i++)
	{
		sum = sum + pow(2 ,i - 1);
	}
	system("cls");
	cout << sum;
	
	return 0;
}
