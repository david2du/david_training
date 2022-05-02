#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int num = 0 ,n = 0 ,m = 0;
	while (1)
	{
		system ("cls");
		m = 0;
		cin >> num;
		n = num;
		for (;n > 0;)
		{
			m = m * 10 +n % 10;
			n = n / 10;
		}
		cout << m << endl;
		if(m == num)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
		system ("pause");	
	}
	
	return 0;
}
