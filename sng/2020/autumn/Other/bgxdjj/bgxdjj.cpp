#include <bits/stdc++.h>
using namespace std;

int main()
{
	int max = 0;
	int idx = 0;
	for (int i = 1; i <= 7; i++)
	{
		int a = 0, b = 0;
		
		cin >> a >> b;
		
		if (((a + b) > 8) && (max < (a + b)))
		{
			max = (a + b);
			idx = i;
		}
	}
	
	cout << idx << endl;
	
	return 0;
} 
