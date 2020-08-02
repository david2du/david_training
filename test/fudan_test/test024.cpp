#include  <iostream>
using  namespace  std;
const  int  N  =  100010;
int  n;
int  L[N],  R[N],  a[N];
int  main()  {
		cin  >>  n;
		for  (int  i  =  1;  i  <=  n;  ++i)  {
			int  x;
			cin  >>  x;
			____(1)____  ;
		}
		for  (int  i  =  1;  i  <=  n;  ++i)  {
			R[i]  =  ____(2)____  ;
			L[i]  =  i  -  1;
		}
		for  (int  i  =  1;  i  <=  n;  ++i)  {
			L[  ____(3)____  ]  =  L[a[i]];
			R[L[a[i]]]  =  R[  ____(4)____  ];
		}
		for  (int  i  =  1;  i  <=  n;  ++i)  {
			cout  <<  ____(5)____  <<  "  ";
		}
		cout  <<  endl;
		return  0;
}
