#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++)
        {
            if ((str[i] >= 'A') && (str[i] <= 'Z'))
            {
                str[i] += 32;
            }
        }

        return str;
    }
};

int main()
{
    Solution s;
    string str;

    cin >> str;

    cout << s.toLowerCase(str) << endl;

    return 0;
}