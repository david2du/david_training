#include <bits/stdc++.h>
using namespace std;

int a[20000], b[20000];
int main()
{
	int n = 0;
	int i = 0, p = 0;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	
	for (i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{
			if (p != i)
			{
				if (a[i] == b[p])
				{
					if (i > p)
					{
						b[i] = -1;
					}
				}
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		if (b[i] != -1)
		{
			/*if (i != (n - 1))
			{
				cout << b[i] << " "; 
			}
			else
			{*/
				cout << b[i] << endl;
			//}		
		}
	}
	
	return 0;
}
