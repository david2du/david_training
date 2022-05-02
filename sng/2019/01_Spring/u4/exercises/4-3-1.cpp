#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int num = 0;
	int month = 0 ,age = 0;
	int numChanged = 0;
	
	cin >> num ;
	
	numChanged = num + 20;
	 
	age = numChanged / 100;
	month = numChanged % 100;
	
	cout << "age:" << age << endl;
	cout << "month:" << month << endl;

	return 0;
}
