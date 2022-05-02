#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int x = 0 ,y = 0 ,z = 0;
	for (x = 0;x < 34;x++)
	{
		for (y = 0;y < 51;y++)
		{
			for (z = 0;z < 101;z += 2)
			{
				if ((x + y + z == 100) && (3 * x + 2 * y + z / 2 ==100))
				{
					cout << "big horse :" << x << endl;
					cout << "mid horse :" << y << endl;
					cout << "small horse :" << z << endl;
					cout << endl << endl << endl << endl; 
				}
			}
		}
	}
	
	return 0;
}
