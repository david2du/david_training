#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int year = 0;
	int a = 0 ,b = 0 ,c = 0 ,d = 0;
	int ab = 0 ,cd = 0;
	int ageX = 0 ,ageM = 0;
	
	cin >> year;
	system ("cls");
	
	a = year / 1000;
	b = year / 100 % 10;
	c = year % 100 % 10;
	d = year % 10;
	
	ab = 10 * a + b;
	cd = 10 * c + d;
	
	ageX = a + b + c + d;
	ageM = ab + cd;
	
	cout << "XiaoMing:" << ageX << endl;
	cout << "Mom:" << ageM << endl;
	 
	return 0;
}
