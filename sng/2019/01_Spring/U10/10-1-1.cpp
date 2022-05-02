#include <bits/stdc++.h>
using namespace std;
int main()
{
	int bYear = 0 ,bAge = 0;
	for (bYear = 1860; bYear < 1964 + 1; bYear++)
	{
		for (bAge = 50; bAge < 120; bAge++)
		{
			if ((bAge * 31 == bYear) && (1964 - bYear > 30) && (1964 - bYear < 100))
			{
				cout << 1964 - bYear << endl; 
			}
		}
	}
	
	return 0;
}
