#include <bits/stdc++.h>
using namespace std;
int getMax (int a,int b,int c)
{
	int max = a;
	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}
	return max;
}
int getMin (int a,int b,int c)
{
	int min = a;
	if (b < min)
	{
		min = b;
	}
	if (c < min)
	{
		min = c;
	}
	return min;
}
int getMid (int a,int b,int c)
{
	int mid = a + b + c - getMax(a ,b ,c) - getMin(a ,b ,c);
	return mid;
}
int main ()
{
	int xz = 0 ,xc = 0 ,xw = 0;
	int x = 0 ,y = 0 ,z = 0;
	int min = 0 ,mid = 0 ,max = 0;
	int min2 = 0 ,mid2 = 0 ,max2 = 0; 
	
	for (xz = 1; xz < 4; xz++)
	{
		for (xc = 1; xc < 4; xc++)
		{
			for (xw = 1; xw < 4; xw++)
			{
				if ((xz == xc) || (xz == xw) || (xc == xw))
				{
					continue;
				}
				
				if ( (xz * xw * xc )!= 6)
				{
					continue;
				} 
					
				x = (xc > xz) + (xw == xz);
				y = (xz > xc) + (xz > xw);
				z = (xw > xc) + (xc > xz);
					
				min = x;
				mid = x;
				max = x;
				min2 = xz;
				mid2 = xz;
				max2 = xz;
					
				min = getMin(x ,y ,z);
				max = getMax(x ,y ,z);
				mid = getMid(x ,y ,z);
						
				if ((max == x) && (xz != 1))
				{
					continue;	
				}
				if (max == y && ( xc != 1))
				{
					continue;
				}
				if ((max == z )&& (xw!= 1))
				{
					continue;
				}
				if ((mid == x ) && (xz != 2))
				{
					continue;	
				}
				if ((mid == y ) && (xc != 2))
				{
					continue;
				}
				if ((mid == z)&& (xw != 2)) 
				{
					continue;
				}
				if ((min == x) && (xz != 3)) 
				{
					continue;	
				}
				if ((min == y) && (xc != 3))
				{
					continue;
				}
				if ((min == z) && (xw != 3))
				{
					continue;
				}
				
				//cout <<xz << ":" << xc << ":" <<xw <<endl;
				min2 = getMin(xz ,xc ,xw);
				max2 = getMax(xz ,xc ,xw);
				mid2 = getMid(xz ,xc ,xw);
				if (max2 == xz)
				{
					cout << "z ";
				}
				if (max2 == xc)
				{
					cout << "c ";
				}
				if (max2 == xw)
				{
					cout << "w ";
				}
				if (mid2 == xz)
				{
					cout << "z ";
				}
				if (mid2 == xc)
				{
					cout << "c ";
				}
				if (mid2 == xw)
				{
					cout << "w ";
				}
				if (min2 == xz)
				{
					cout << "z ";
				}
				if (min2 == xc)
				{
					cout << "c ";
				}
				if (min2 == xw)
				{
					cout << "w ";
				}															
			}
		}
	}
	
	return 0;	
}
