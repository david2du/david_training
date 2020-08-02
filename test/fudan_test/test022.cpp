#include<iostream>
using  namespace  std;
const  int  SIZE=10000;
int  main()  {
	int  a[SIZE],b[SIZE];
	int  i,j,n,p;
	cin>>n;
	for  (i=1;  i<=n;  i++)
		cin>>a[i];
	cin>>p;
	for  (i=1;  i<=p;  i++)
		b[i]=a[i];
	for  (i=p+1;  i<=n;  i++)
		b[i-p]  =  a[i];
	for  (i=1;  i<=n;  i++)
		a[i]=b[i];
	for  (i=1;  i<=n;  i++)
		cout<<a[i]<<"  ";

	return 0;
}
