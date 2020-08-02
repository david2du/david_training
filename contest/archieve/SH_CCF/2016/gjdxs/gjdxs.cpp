#include <iostream>
using namespace std;

int main()
{
	freopen("gjdxs.in", "r", stdin);
	freopen("gjdxs.out", "r", stdout);
	
	int a = 0, b = 0;
	int q = 0, r = 0;
	int n = 0;
	
	cin >> a >> b;
	
	q = a / b;
	r = a % b;
	a = r;
	cout << q;
	
	if (r != 0)
	{
		cout << ".";
		while ((r != 0) && (n <= 10))
		{
			a *= 10;
			q = a / b;
			r = a % b;
			a = r;
			cout << q;
			n++;
		}
	}

	return 0;
}
