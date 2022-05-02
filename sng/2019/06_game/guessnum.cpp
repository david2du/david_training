#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) ,a);
}
int main()
{
	int n = 0 ,num1 = 0 ,num2 = 0;
	int count = 0 ,a = 0 ,b = 0 ,ia = 0 ,ib = 0;
	bool flag = false;
	
	srand(time(0));
	
	for (;true;)
	{
		for (;true;)
		{
			cout <<"LEVEL :" << endl << endl;
			cout << "3λ(1)" << endl;
			cout << "4λ(2)" << endl;
			cout << "5λ(3)" << endl;
			cout << "6λ(4)" << endl;
			cout << "please input number" << endl;
			cin >> n ;
			if ((n < 1) || (n > 3))
			{
				cout << "error!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				break;
			}
		}
		if (n == 1)
		{
			for (;true;)
			{
				num1 = rand() % 900 + 100;
				a = num1;
				
				cin >> num2 ;
				b = num2;
				
				vector<int> va;
				vector<int> vb;
				for(count = 1;count < 4;count++)
				{
					va.push_back(a % 10);
					vb.push_back(b % 10);
					a = a / 10;
					b = b / 10;
				}
				
				
				for(ib = vb.size() - 1;ib >= 0;ib--)
				{
					flag = false;
					for(ia = va.size() - 1;ia >= 0;ia--)
					{
						if(vb[ib] == va [ia])
						{
							flag = true;
							if(ib == ia)
							{
								color(10);  	
							}
							else
							{
								color(14);
							}
							cout << vb[ib];
							break;
						}
					}
					if(!flag)
					{
						color(12);
						cout << vb[ib];						
					}
				}
				
				system("pause");
				system("cls");
				
			}
		}
		if (n == 2)
		{
			for (;true;)
			{
				num1 = rand() % 9000 + 1000;
				cout << num1 << endl;
				a = num1;
				
				cin >> num2 ;
				b = num2;
				
				vector<int> va;
				vector<int> vb;
				for(count = 1;count < 5;count++)
				{
					va.push_back(a % 10);
					vb.push_back(b % 10);
					a = a / 10;
					b = b / 10;
				}
				for(ib = vb.size() - 1;ib >= 0;ib--)
				{
					flag = false;
					for(ia = va.size() - 1;ia >= 0;ia--)
					{
						if(vb[ib] == va [ia])
						{
							flag = true;
							if(ib == ia)
							{
								color(10);  	
							}
							else
							{
								color(14);
							}
							cout << vb[ib];
							break;
						}
					}
					if(!flag)
					{
						color(12);
						cout << vb[ib];						
					}
				}
				
				system("pause");
				system("cls");
				
			}
		}
		if (n == 3)
		{
			for (;true;)
			{
				num1 = rand() % 90000 + 10000;
				cout << num1 << endl;
				a = num1;
				
				cin >> num2 ;
				b = num2;
				
				vector<int> va;
				vector<int> vb;
				for(count = 1;count < 6;count++)
				{
					va.push_back(a % 10);
					vb.push_back(b % 10);
					a = a / 10;
					b = b / 10;
				}
				for(ib = vb.size() - 1;ib >= 0;ib--)
				{
					flag = false;
					for(ia = va.size() - 1;ia >= 0;ia--)
					{
						if(vb[ib] == va [ia])
						{
							flag = true;
							if(ib == ia)
							{
								color(10);  	
							}
							else
							{
								color(14);
							}
							cout << vb[ib];
							break;
						}
					}
					if(!flag)
					{
						color(12);
						cout << vb[ib];						
					}
				}
				
				system("pause");
				system("cls");
				
			}
		}
		if (n == 4)
		{
			for (;true;)
			{
				num1 = rand() % 900000 + 100000;
				cout << num1 << endl;
				a = num1;
				
				cin >> num2 ;
				b = num2;
				
				vector<int> va;
				vector<int> vb;
				for(count = 1;count < 7;count++)
				{
					va.push_back(a % 10);
					vb.push_back(b % 10);
					a = a / 10;
					b = b / 10;
				}
				for(ib = vb.size() - 1;ib >= 0;ib--)
				{
					flag = false;
					for(ia = va.size() - 1;ia >= 0;ia--)
					{
						if(vb[ib] == va [ia])
						{
							flag = true;
							if(ib == ia)
							{
								color(10);  	
							}
							else
							{
								color(14);
							}
							cout << vb[ib];
							break;
						}
					}
					if(!flag)
					{
						color(12);
						cout << vb[ib];						
					}
				}
				
				system("pause");
				system("cls");
				
			}
		}
	}  	
	
	return 0;
} 
