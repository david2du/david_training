#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k = 0;
	unsigned int i = 0;
	string s;
	bool found = false;
	int sum = 1;
	
	cin >> k;
	cin >> s;
	
	for (i = 0; i < (s.size() - 1); i++)
	{
		if (s[i] == s[i + 1])
		{
			sum++;
			if (sum >= k)
			{
				found = true;
				break;
			}
			continue;
		}
		sum = 1;
	}
	
	if (found == true)
	{
		cout << s[i] << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
	return 0;
}
