#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("czzm.in", "r", stdin);
	freopen("czzm.out", "w", stdout);
	
	int n = 0;
	string s;
	char f;
	unsigned int i = 0;
	
	getline(cin, s);
	cin >> f;
	
	if (s.find(f) != -1)
	{
		for (i = 0; i < s.size(); i++)
		{
			cout << s[i];
			if ((s[i] == f) && (n < 3))
			{
				n++;
				printf("(%d)", n);
			}
		}
	}
	else
	{
		cout << 0;
	}
	cout << endl; 
	
	return 0;
}
