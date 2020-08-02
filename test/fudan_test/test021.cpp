#include<iostream>
using  namespace  std;
int  i, j, k, n, x, b[101];
int  main()  
{
	cin >> n;
	for(i = 0; i <= 100; i++)  
	{
		b[i]=0;
	}
	for(i = 1; i <= n; i++)  
	{
		cin >> x;
		b[x] = b [x] + 1;
	}
	k = 0;
	for(i = 0; i <= 100; i++)
	{
		while(b[x] > 0)  
		{
			cout << i << " ";
			k = k + 1;
			b[i] = b[i] - 1;
			if(k % 8 == 0)
			{
				cout<<endl;
			}
		}
	}
	cout << endl;
	
	return  0;
}

