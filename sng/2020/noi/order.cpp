#include <bits/stdc++.h>
using namespace std; 

int main() 
{
    int sum = 0;

    freopen("order.in", "r", stdin);
    freopen("order.out", "r", stdout);
    int c=0, p=0, n=0, amin=0, asum=0; 
    int rc=0, rp=0, rn=0, rsum=0, rmin=0;
    bool find = false; 


    cin >> sum;

    for(int c = 1; c <= sum/7; c++)
        for (int p = 1; p <= sum/4; p++)
            for (int n =1; n <= sum/3;n++ )
            {
                if ( 7*c + 4 * p + 3 *n == sum)
                {
                    amin = min(c, min(p, n));
                    asum = c + p + n; 
                   
                    if (!find|| (amin > rmin) || (amin == rmin && asum > rsum))
                    {
                        rc = c; 
                        rp = p ; 
                        rn = n; 
                        rmin = amin;
                        rsum = asum;
                        if (!find)
                            find = true; 
                    }
                   
                    
                }
            }

    if(!find)
        cout << "-1" <<endl;    
    else
    {
        printf("%d %d %d\n", rc, rp, rn);
    }
    

    return 0; 
}