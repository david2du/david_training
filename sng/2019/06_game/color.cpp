#include <iostream>
#include <windows.h>
using namespace std;
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) ,a);
}
int main()
{
	int n = 0;
	for (n = 0;n < 300;n++)
	{
		color(n);
		cout << n << endl;
	}
}
