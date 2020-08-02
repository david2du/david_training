#include <iostream>
using namespace std;

int main()
{
	freopen("zxzds.in", "r", stdin);
	freopen("zxzds.out", "w", stdout);
	
	int low = 0, high = 0, x = 0;
	int n = 0, m = 0;
	int sum = 0;
	int i = 0, j = 0;
	
	cin >> low >> high >> x;
	
	for (i = 1; i <= high; i++)
	{
		j = i;
		
		while(j != 0)
		{
			sum += (j % 10);
			j /= 10; 
		}
		if (sum == x)
		{
			n = i;
			break;
		}
		sum = 0;		
	}
	
	for (i = high; i >= 1; i--)
	{
		j = i;
		
		while(j != 0)
		{
			sum += (j % 10);
			j /= 10; 
		}
		if (sum == x)
		{
			m = i;
			break;
		}
		sum = 0;
	}
	
	cout << n << endl << m << endl;
	
	return 0;
}
