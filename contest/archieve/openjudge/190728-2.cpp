#include <bits/stdc++.h>//2min 35s
using namespace std;
int main()
{
	int a = 0, b = 0;
	
	cin >> a >> b;
	
	if (a > b)
	{
		cout << ">" << endl;
	}
	
	else if (a == b)
	{
		cout << "=" << endl;
	}
	
	else
	{
		cout << "<" << endl;
	}
	
	return 0;
}