#include <bits/stdc++.h>
using namespace std;
bool judgeNum (int num)
{
	int a = 0 ,b = 0 ,c = 0 ;
	bool retval = false;

	a = num / 100;
	b = num / 10 % 10;
	c = num % 10;
	
	if ((a == b) || (a == c) || (b == c))
	{
		retval = false;	
	}
	else
	{
		retval = true;
	}

	return retval;	
}

int getMaxNum (int num)
{
	int a = 0 ,b = 0 ,c = 0 ;
	int max = 0;
		
	a = num / 100;
	b = num / 10 % 10;
	c = num % 10;
	
	max = a;
	
	if (max < b)
	{
		max = b;
	}	
	if (max < c)
	{
		max = c;
	}
	
	return max;	
}

int getMinNum (int num)
{
	int a = 0 ,b = 0 ,c = 0 ;
	int min = 0;
		
	a = num / 100;
	b = num / 10 % 10;
	c = num % 10;
	
	min = a;
	
	if (min > b)
	{
		min = b;
	}	
	if (min > c)
	{
		min = c;
	}
	
	return min;	
}

int getMidNum (int num)
{
	int a = 0 ,b = 0 ,c = 0 ;
	int mid = 0 ,min = 0 ,max = 0;
		
	a = num / 100;
	b = num / 10 % 10;
	c = num % 10;
	
	min = getMinNum (num);
	max = getMaxNum (num);
	
	mid = a + b + c - min - max;
	
	return mid;	
}

int comNum (int num)
{
	int max = 0 ,mid = 0 ,min = 0;
	int newNum1 = 0 ,newNum2 = 0;
	int delta = 0;
	
	max = getMaxNum (num);
	mid = getMidNum (num);
	min = getMinNum (num);
	
	newNum1 = max * 100+ mid * 10+ min;
	newNum2 = min * 100+ mid * 10+ max;
	
	delta = newNum1 - newNum2;
	return delta;		 
}
int main ()
{
	int n = 0 ,time = 0 ,newNum = 0 ,oldNum = 0;
	
	cin >> n;
	if (judgeNum (n) == false)
	{
		cout << "error!!!" <<endl;
		return -1;
	}
	
	newNum = n;
	 
	do
	{
		oldNum = newNum; 
		newNum = comNum (oldNum);
		if (newNum == oldNum)
		{
			break;
		}
		time++;
		cout << newNum << endl;
	}
	while(newNum != oldNum);
	cout << time << endl;
	
	return 0;
} 
