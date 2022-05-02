#include <iostream>
#include <windows.h>
using namespace std;

void textcolor(int c)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}

int main()
{
	int i = 0;
	
	for (int i = 0; i < 20; i++)
	{
		textcolor(i);
		cout << i << endl;
	}
	
	return 0;
}
