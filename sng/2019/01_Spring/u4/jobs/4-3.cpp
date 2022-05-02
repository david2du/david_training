#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0 ,b = 0 ;
	while(1)
	{
		system("cls");
		srand(time(0));
		b = rand()%3+1;
		
			
		cout << "rock = 1 , scissors = 2 , paper = 3" << endl;
		cout << " A input :" << endl;
		
		cin >> a;
		if((a != 1) && (a != 2) && (a != 3))
		{
			cout << "wrong input !"<<endl;
			continue;
		}
		
		if((b - a == 1) || (a - b == 2))
		{
			cout << "YOU WIN" << endl;
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
		system ("pause");
	}
	return 0;
}
