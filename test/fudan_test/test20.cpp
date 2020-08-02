#include<iostream>
using namespace std;
int main()  
{
	int n = 0, i = 0;
	cin >> n;
	if (n == 2)  
	{
		cout << "YES";
	}
	else  if((n < 2) || (n % 2 ==0))
	{
		cout << "NO";
	}
	else  
	{
		i = 3;
		while(i * i <= n)  
		{
			if (n % i == 0)  
			{
				cout << "NO";
				return  0;
			}
			i = i + 2;
		}
		cout << "YES";
	}
	return  0;
}

