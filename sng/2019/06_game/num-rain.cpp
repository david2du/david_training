#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	
	srand(time(0));
	system("color 2");
	
	while(true)
	{
		n = rand() % 2;
		cout << setw(6) << n ;
	}
	
	return 0;
} 
