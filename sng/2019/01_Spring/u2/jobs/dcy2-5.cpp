#include <iostream>
using namespace std;
int main()
{
	
	int a = 12, b = 13 ,c = 11 , d = 0;
	d = a;
	a = c;
	c = b;
	b = d;

	
    cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
    return 0;
}
