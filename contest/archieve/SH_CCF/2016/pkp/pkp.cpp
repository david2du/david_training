#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("pkp.in", "r", stdin);
	freopen("pkp.out", "w", stdout);
	
	int s[14] = {0}, sn = 13;
	int d[14] = {0}, dn = 13;
	int h[14] = {0}, hn = 13;
	int c[14] = {0}, cn = 13;
	string str;
	int n = 0;
	unsigned int i = 0;
	
	getline(cin, str);
	
	for (i = 0; i < str.size(); i += 3)
	{
		n = 10 * (str[i + 1] - '0') + (str[i + 2] - '0');
		if (str[i] == 'S')
		{
			s[n]++;
			sn--;
		}
		if (str[i] == 'D')
		{
			d[n]++;
			dn--;
		}
		if (str[i] == 'H')
		{
			h[n]++;
			hn--;
	    }
		if (str[i] == 'C')
		{
			c[n]++;
			cn--;
		}
	}
	
	for (i = 0; i < 14; i++)
	{
		if ((s[i] > 1) || (d[i] > 1) || (h[i] > 1) || (c[i] > 1))
		{
			cout << "error" << endl;
			return 0;
		}
	}
	
	printf("%d %d %d %d\n", sn, dn, hn, cn);
	
	return 0;
}
