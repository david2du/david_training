#include <bits/stdc++.h>
using namespace std;
int main()
{
	string n[5];
	int i = 0, j = 0;

	for (i = 0; i < 5; i++)
	{
		cin >> n[i];
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < (4 - i); j++)
		{
			if (n[j].size() > n[j + 1].size())
			{
				swap(n[j], n[j + 1]);
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		if (i < 5)
		{
			cout << n[i] << " ";
			continue;
		}
		cout << n[i] << endl;
	}
	getchar(); getchar();
	
	return 0;
}