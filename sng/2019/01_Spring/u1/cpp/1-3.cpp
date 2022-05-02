#include<iostream>
using namespace std;
int main()
{
	int a = 1;
	
	a = a + a;
	a = a * a * a * a * a * a * a * a \
			+ a * a * a * a * a * a \
			+ a * a * a * a * a \
			+ a * a * a \ 
			+ a * a \
			+ a / a;
	cout << "a	=	" << a << endl;
	
	getchar();	
	return(0);	
}

