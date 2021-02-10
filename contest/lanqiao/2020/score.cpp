#include <bits/stdc++.h>
using namespace std;

int main()
{
    const string TRUE_ANS = "DCBAD";
    string ans;
    int sum = 0;
    
    cin >> ans;

    for (unsigned int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == TRUE_ANS[i])
        {
            sum += 30;
        }
    }

    cout << sum << endl;

    return 0;
}