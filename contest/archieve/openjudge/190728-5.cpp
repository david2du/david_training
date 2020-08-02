#include <bits/stdc++.h> //7min 54s 
using namespace std;
int main()
{
	int l = 0;
	double tw = 0, tb = 27 + 23;
	
	cin >> l;
	
	tb += l / 3.0;
	tw += l / 1.2;
	
	if (tb > tw)
	{
		cout << "Walk" << endl;
	} 
	else if (tb == tw)
	{
		cout << "All" << endl;
	}
	else 
	{
		cout << "Bike" << endl;
	}
	
	return 0;
}
