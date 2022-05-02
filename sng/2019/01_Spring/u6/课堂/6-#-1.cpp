#include<bits/stdc++.h>
using namespace std;
int getLoop (int num)
{
	int num1 = 0;
	int num2 = 0;
	num1 = num;
	while (num1 != 0)
	{
		num2 = num2 * 10 + num1 % 10;
		num1 = num1 / 10;
	}
	return num2;
}
int main ()
{
	int n = 0 ,loopNum = 0;
	
	cin >> n;
	
	loopNum = getLoop(n);
	cout << loopNum << endl;
	return 0;
	
}
