#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num = 0 ,scoreA = 0 ,scoreB = 0;
	int a = 0 ,b = 0 ;
	int count = 0;
	
	srand(time(0));
	
	for (count = 1;count < 6;count++)
	{
		cout << "round	" << count << endl << endl;
		
		num = rand() % 90 + 10;
		for (;true;)
		{
			cout << endl << "A input:	";
			cin >> a;
			
			if (a < num)
			{
				cout << "	small!!!" << endl;
			}
			else if (a > num)
			{
				cout << "	big!!!" << endl;
			}
			
			else
			{
				cout << "	Player A win this round,another round!"<< endl;
				cout << "------------------------------" << endl;
				scoreA++;
				break;
			}
			
			
			cout << endl << "B input:	";
			cin >> b;
			
			if (b < num)
			{
				cout << "	small!!!" << endl;
			}
			else if (b > num)
			{
				cout << "	big!!!" << endl;
			}
			
			else
			{
				cout << "	Player B win this round,another round!"<< endl;
				cout << "-------------------------------------" << endl;
				scoreB++;
				break;
			}	
		}
	}
	
	if (scoreA > 2)
	{
		cout << " 		PLAYER A WINS !!!" << endl;	
	}
	else
	{
		cout << " 		PLAYER B WINS !!!" << endl;	
	}	
	 
	return 0;
} 
