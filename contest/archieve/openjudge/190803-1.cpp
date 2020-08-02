#include <bits/stdc++.h>
using namepsace std;
int main()
{
	int n = 0;
	int a[30][100] = {0};
	char ch;
	int i = 0, p = 0, max = 0;
	
	cin >> n;
	for(i = 0; i < n; i++)
	{
		for (int p = 0; p < 100; p++)
		{
			cin >> a[i][p];
			ch = getchar();
			if (ch = '\n')
			{
				break;
			}
		}
	} 
	
	
	
	return 0;
}
