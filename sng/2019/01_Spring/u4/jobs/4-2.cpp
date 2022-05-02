#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0 ,b = 0;
	while(1)
	{
		system("cls");
		cout << "rock = 1 , scissors = 2 , paper = 3" << endl;
		cout << " A input :" << endl;
		
		cin >> a;
		system("cls");
		
		cout << "rock = 1 , scissors = 2 , paper = 3" << endl;
		cout << " B input :" << endl;
		
		cin >> b;
		system("cls");
			
		if((b - a == 1) || (a - b == 2))
		{
			cout << "PLAYER A WIN" << endl;
			cout << a << endl;
			cout << b << endl;
		}
		else if((a - b == 1) || (b - a == 2))
		{
			cout << "PLAYER B WIN" << endl;
			cout << a << endl;
			cout << b << endl;
		}
		else 
		{
			cout << "DRAW" << endl;
			cout << a << endl;
			cout << b << endl;	
		}
		
		system("pause");
		
	}
	return 0;
}
