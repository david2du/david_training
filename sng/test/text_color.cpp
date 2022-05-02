#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
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
	
	for (i = 0; i < 256; i++)
	{
		textcolor(i);
		cout << i << endl;
	}

	getchar();
	return 0;
}
