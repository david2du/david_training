#include<iostream>
using namespace std;
int main()
{
	int a[3],b[3];
	int i,j,tmp;
	for (i=0;i<3;i++)
		cin >> b[i];
	for (i=0;i<3;i++)
	{
		a[i]=0;
		for (j=0;j<=i;j++)
		{
			a[i]+=b[j];
			b[a[i]%3]+=a[j];
		}
	}
	tmp=1;
	for (i=0;i<3;i++)
	{
		a[i]%=10;
		b[i]%=10;
		tmp*=a[i]+b[i];
	}
	cout << tmp << endl;
	return 0;
}

