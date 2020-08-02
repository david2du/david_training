#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, tot = 0;
    int i = 0;

    cin >> n;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while(n % i == 0)
            {
                tot++;
                if(tot == 1)
                {
                    cout << i;
                }
                else
                {
                    cout << "*" << i;
                }
                n /= i;
            }
        }
    }
    
    if (n != 1)
    {
    	if (tot == 1)
    	{
    		cout << n;
		}
		else
		{
			cout << "*" << n;
		}
	}
	
	cout << endl;

    return 0;
}
