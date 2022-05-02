#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long num[100000] = {0};
int target[10000] = {0};

int main()
{
	int n = 0, m = 0;
	int min = 0, min_index = 0;
	int i = 0, j = 0;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> target[i];
	}
	
	for (i = 0; i < m; i++)
	{
		min = abs(target[i] - num[0]);
		for (j = 0; j < n; j++)
		{
			if (abs(target[i] - num[j]) < min)
			{
				min = target[i] - num[j];
				min_index = j;
			}
		}
		cout << num[min_index] << endl;
	}
	
	return 0;
}
