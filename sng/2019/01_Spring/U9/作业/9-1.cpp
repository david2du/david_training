#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0 ,b = 0;
	int c = 0 ,delta = 0;
	int score = 0 ,count = 0;
	
	srand(time(0));
	
	for(count = 1;count < 11;count++)
	{
		a = rand() % 90 + 10;
	
		b = rand() % 90 + 10;
		
		if (a >= b)
		{
			delta = a - b;
			cout << a << "-" << b << "=" ;
		}
		else
		{
			delta = b - a;
			cout << b << "-" << a << "=" ;
		}
		
		cin >> c;
		
		if (c == delta)
		{
			score += 10;
			cout << "right !" << endl;
		}
		else
		{
			cout << "wrong !" << endl;
		}
		system("pause");
		system("cls"); 
	}
	cout << "score : " << score << endl;
	system("pause");
	system("cls");
	
	return 0;
} 
