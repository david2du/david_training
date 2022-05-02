#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0 ,b = 0 ,c = 0 ,d = 0 ,e = 0;
	int h = 0;
	 
	for (h = 7;h < 1001;h++)
	{
		for (a = 1;a < 1000 / 2 + 1;a++)
		{
			
			for (b = 1;b < 1000 / 3 + 1;b++)
			{
				if ( 2 * a +b != h)
				{
					continue;
				}	
					
				for (c = 1;c < 1000 / 4 + 1;c++)
				{
					if ( 3 * b + c != h)
					{
						continue;
					} 
						
					for (d = 1;d < 1000 / 5 + 1;d++)
					{
						if ( 4 * c + d != h)
						{
							continue;
						} 
							
						for (e = 1;e < 1000 / 6 + 1;e++)
						{
							if ((2 * a + b == h)\
							&& (3 * b + c == h)\
							&& (4 * c + d == h)\
							&& (5 * d + e == h)\
							&& (6 * e + a == h))
							{
								cout << "A = " << a << "cm" <<endl;
								cout << "B = " << b << "cm" <<endl;
								cout << "C = " << c << "cm" <<endl;
								cout << "D = " << d << "cm" <<endl;
								cout << "E = " << e << "cm" <<endl;
								cout << "Height = " << h << "cm" <<endl;
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
} 
