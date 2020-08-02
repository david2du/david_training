#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	string medName;
	int i = 0;
	string mn[100];
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> medName;
		if ((medName[0] >= 'a') && (medName[0] <= 'z'))
		{
			medName[0] -= 32;
		}
		for (int a = 1; a < medName.size(); a++)
		{
			if ((medName[a] >= 'A') && (medName[a] <= 'Z'))
			{
				medName[a] += 32;
			}
		}
		
		mn[i] = medName; 
		//cout << medName << endl;
	}
	
	for (i = 0; i < n; i++)
	{
		cout << mn[i] << endl;
	}
	
	return 0;
}
