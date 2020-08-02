#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> vb;

        for (int i = 0; i < A.size(); i++)
        {
            vb.push_back(pow(A[i], 2));
        }   
        sort(vb.begin(), vb.end());

        return vb;
    }
};

int main()
{
    vector <int> a;
    vector <int> b;
    Solution n;

    b = n.sortedSquares(a);

    cout << b << endl;

    return 0;
}