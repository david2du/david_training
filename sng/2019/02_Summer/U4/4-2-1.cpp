#include <bits/stdc++.h>
using namespace std;
int  mx = 7;
void starts(int n)
{ 
	int k = 0;
    for(k = 0; k < n; k++)
    {
    	printf("*");
	}
}
void space(int m, int n)
{ 
	int k = 0;
    for(k = 0; k <= n; k += 2) 
	{
		printf(" %d",m);
	}
}
void pattern(int p)
 {
   starts(1);  
   space(p, mx - 4);
   if(mx % 2 == 1) 
   {
		printf(" ");
   }
	starts(1);
 }

int main()
{ int k = 0;
  system("cls");
  for(k = 0; k < mx; k++)
     {  if((k < 2) || (k >= mx - 2))  
	    {
	    	starts(mx); 	
		}
        else 
		{
			pattern(k);	
		}  
		printf("\n");
     }
}

