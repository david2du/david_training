#include <iostream>
using namespace std;
int main()
{
	
	int a = 1, b = 2 ,c = 0;

	c = b;
	b = a;
	a = c;
    cout << "a = " << a << endl;
	cout << "b = " << b << endl;
    return 0;
}
