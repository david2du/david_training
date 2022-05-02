#include <bits/stdc++.h>
using namespace std;

string csec(string init, char p, int n)
{
	int i = 0;
	string sec = init;
	
	if (p == 'f')
	{
		for (i = 0; i < init.size(); i++)
		{
			if (((init[i] > 'A') && (init[i] < 'Z')) || \
			    ((init[i] > 'a') && (init[i] < 'z')))
			{
				sec[i] -= n;
				sec[i] = sec[i] % 26;	
			}
		}
	}
	else if (p == 'b')
	{
		for (i = 0; i < init.size(); i++)
		{
			if (((init[i] > 'A') && (init[i] < 'Z')) || \
			    ((init[i] > 'a') && (init[i] < 'z')))
			{
				sec[i] += n;
				
				sec[i] = (sec[i] - 'a');	
			}
		}
	}
}

int main()
{
	string init;
	string sec;
	char p;
	int n = 0;
	
	cin >> p >> n;
	getline(cin, init);
	
	sec = csec(init, p, n);
	
	cout << sec << endl;

	return 0;
} 
