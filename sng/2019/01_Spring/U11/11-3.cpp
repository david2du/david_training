#include <bits/stdc++.h>
using namespace std; 

int main()
{
	int a , b, c , d ; 
	int A, B, C , D ;
	
	for (a = 0; a < 2; a++)
	{
		for (b = 0; b < 2; b++)
		{
			for (c = 0; c < 2; c++)
				{
					for (d = 0; d < 2; d++)
					{
						A = (a == 0);
						B = (c == 1);
						C = (d == 1);
						D = (d == 0);
						
						if( a + b + c + d >1)
							continue;
						
						if (A + B + C + D != 3)
							continue;
						if (A*B != 1)
							continue;
						if ((C == 1 && D == 0) || \
							(C == 0) && (D == 1))
						{
							/*cout << a <<endl;
							cout << b <<endl;
							cout << c <<endl;
							cout << d <<endl;
							cout <<"---------"<<endl; */
							if (c == 1)
								cout <<"c"<<endl;
							if (d == 1)
								cout << "d"<<endl;
						}
						
					}
				}
		}
	}
 } 
