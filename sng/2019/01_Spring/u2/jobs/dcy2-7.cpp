#include <iostream>
using namespace std;
int main()
{
	
	int a = 1, b = 2 ,c = 3 , d = 4 , e = 0;
	e = b;
	b = c;
	c = e;
	
	e = a;
	a = d;
	d = e; 

	
    cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

    return 0;
}
