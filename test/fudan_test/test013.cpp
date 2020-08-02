#include<iostream>
using  namespace  std;

const  int  N = 1005;
int  a[N] = {0}, n = 0, k = 0;

void  swap(int  &a,  int  &b) 
{
	int t = 0;
	t = a;
	a = b;  
	b = t;
}

int  main()  {
	int  i = 0, j = 0, t = 0, val = 0;
	
	cin >> n>> k;
	
	for(int i = 0; i < n; i++)  
	{
		cin>>a[i];
	} 
	
	i = 0;
	j = n - 1;
	val = a[k];
	
	while(i < j)  
	{
		while(a[i] < val)
		{
			i++;
		}
		 
		while(a[j] > val)
		{
			j--;
		}
		 
		if()
		{
			swap(____________);
		}	
	}
	
	for(int i = 0; i < n; i++)  
	{
		cout << a[i] << "  ";
	}
	 
	return  0;
}
 
