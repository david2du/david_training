#include<iostream>
using  namespace  std;
long  k,m,begin;
int  check(long  remain)  {
		long  result=(begin+m+1)%remain;
		if(result>=k)  {
			begin=result;  return  1;
		}
		else  return  0;
}
int  main()  {
		long  i,find=0;
		cin>>k;
		m=k;
		while(!find)  {
			find=1;  begin=0;
			for(i=0;i<k;i++)
				if(!check(2 * k - i)){
					find=0;break;
				}
			m++;
		}
		cout<<m-1;
		return 0;
}
