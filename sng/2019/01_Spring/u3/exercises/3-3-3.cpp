#include <bits/stdc++.h>
using namespace std;
int main ()
{
	double a = 0, b = 0, c = 0;
	double s = 0;
	double area = 0;
	cin >> a >> b >> c;
	
	if ((a + b <= c)\
	  || (a + c <= b)\
	  || (b + c <= a))
	{
		cout << "Data error!" << endl;
		return 1; 
	}
	
	s=(a+b+c)/2;  
    area=sqrt(s*(s-a)*(s-b)*(s-c)) ;
	cout << "The area is " << area << endl;
	
	return 0;
}
