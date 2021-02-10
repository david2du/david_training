#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;

    cin >> n;

    int even = 0, odd = 0;

    for (int i = 0; i < n; i++)
    {
        int a = 0;

        cin >> a;
        if (a % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    int cnt = 0;

    while (odd != 0)
    {
        cnt++;
        //cout << "Round " << cnt << ": ";
        if (cnt % 2 == 1)
        {
            if (even > 0)
            {
                even--;
                //cout << "even 1, Left: " << even << endl;
            }
            else
            {
                if (odd > 1)
                {
                    odd -= 2;
                    //cout << "odd 2, Left: " << odd << endl;
                }
                else
                {
                    //cerr << "Error. Cnt: " << cnt << "Even: " << even << "Odd: " << odd << endl;
                    cnt -= 2;
                    break;
                }
            }
        }
        else
        {
            if (odd > 0)
            {
                odd--;
                //cout << "odd 1, Left: " << odd << endl;
            }
            else
            {
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}