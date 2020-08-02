#include <bits/stdc++.h>
using namespace std;
int main()
{
	int sc[8] = {0}, ex[8] = {0}, al[8] = {0};
	int i = 0, max = 0;
	int n = 0;
	for ( i = 1; i < 8; i++)
	{
		cin >> sc[i] >> ex[i];
		al[i] = sc[i] + ex[i];
	}
	max = al[1];
	for (i = 2; i < 8; i++)
	{
		if (al[i] > max)
		{
			max = al[i];
			n = i; 
		}
	}
	if (max < 9)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << n << endl;
	}
	
	return 0;
}
