#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Q1() {
        vector<int> iv;
        iv.push_back(26);
        iv.push_back(37);
        iv.push_back(103);

        return iv;
    }
};

int main()
{
    vector<int> iv;
    Solution s;
    iv = s.Q1();

    for ( unsigned int i = 0; i < iv.size(); i++)
    {
        cout << iv[i] << endl;
    }

    return 0;
}