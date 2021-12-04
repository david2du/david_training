#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;

    cin >> s;

    int cnt = 0;
    for (string::size_type i = 0; i < s.size(); i++)
    {
        cnt += (s[i] >= '0' && s[i] <= '9');
    }

    cout << cnt << endl;

    return 0;
}
