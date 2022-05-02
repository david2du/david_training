#include <iostream>
using namespace std;
int main()
{
	int a = 0, b = 0;
	
	a = 3, b = 5;
	b = a + a;
	a = b + b;
	//printf("a = %d , b = %d \n", a, b);
	cout<<"a = "<<a<<",		b = "<<b<<endl;
	return(0);	
}

