#include <bits/stdc++.h>//2min 44s
using namespace std;
int main()
{
	int a = 0, b = 0;
	
	cin >> a >> b;
	
	if (((a < 60) && (b < 60)) || ((a > 59) && (b > 59)))
	{
		cout << "0" << endl;
	}
	else 
	{
		cout << "1" << endl;
	}
	
	return 0;
}
