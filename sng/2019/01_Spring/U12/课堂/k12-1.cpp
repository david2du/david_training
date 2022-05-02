#include <bits/stdc++.h>
#include <windows.h> 
using namespace std;

const int NUM = 20;
const int TIME = 10 * 1000;

int main()
{
	int i = 0 ,a = 0 ,r = 0;
	int t = 0 ,n = 0;
	int A[NUM];
	char judge;
	
	for(;true;)
	{
		system("cls");
		srand(time(0));
		system ("color 9A");
		cout << "	Challenging digital memory" << endl << endl; 
		
		for (i = 0; i < NUM; i++)
		{
			a = rand() % 10;
			A[i] = a;
			cout << "	" << a; 
		}
		Sleep(TIME);
		system("cls");
		
		r = rand() % NUM + 1;
		cout << "NO." << r << " : " << endl;
		
		t = A[r - 1];
		for (;true;)
		{
			cin >> n;
			if ((n < 0) || (n > 10))
			{
				cout << "input error!!!" << endl;
				cout << "NO." << r << " : " << endl;
			}
			else
			{
				break;
			}
		}
		cout << endl << endl;
		
		if (n == t)
		{
			cout << "YES!" << endl;
			cout << "NO." << r << " is " << t << endl << endl;
		}
		else
		{
			cout << "NO!" << endl;
			cout << "NO." << r << " is " << t << endl << endl;
		}
		for (i = 0; i < NUM; i++)
		{
			cout << "	" << A[i]; 
		}
		cout << endl;
		
		for (;true;)
		{
			cout << "another round???(n/y)" << endl;
			cin >> judge;
			if((judge != 'n') && (judge != 'y'))
			{
				cout << "input error!!!" << endl << endl; 
			}
			else
			{
				if (judge == 'y')
				{
					break;
				}
				if (judge == 'n')
				{
					return 0;
				}
			}
		}
	}
		
	return 0;
}
