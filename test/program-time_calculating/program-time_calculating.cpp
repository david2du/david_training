#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int main()
{
	clock_t a, b;
	a = clock();
	/* code */
	for (int i = 0; i < 1e9; i++)
	{
	}

	b = clock();
	
	cout << (double)(b - a) / CLOCKS_PER_SEC << "s" << endl;

	/*----------------------------------------------------------------------------------------------------*/
     
	cout << "test01" << endl;
	a = clock();
	/* code */
	for (int i = 0; i < N; i++)
	{
		cout << "test: " << i << endl;
	}

	b = clock();
	
	cout << (double)(b - a) / CLOCKS_PER_SEC << "s" << endl;

	/*----------------------------------------------------------------------------------------------------*/

	cout << "test02" << endl;
	a = clock();
	/* code */
	for (int i = 0; i < N; i++)
	{
		printf("test: %d\n", i);
	}

	b = clock();
	
	cout << (double)(b - a) / CLOCKS_PER_SEC << "s" << endl;
	
	return 0;
}
