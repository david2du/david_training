#include <bits/stdc++.h>
using namespace std; 

class Solution
{
private:
    int pown[16];
    vector<int> num;

    void pow_init()
    {
        pown[0] = 1;
        for (int i = 1; i <= 9; i++)
        {
            pown[i] = pown[i - 1] * i;
        }
    }
    vector<int>::iterator get_vector_iterator(int idx)
    {
        vector<int>::iterator it = num.begin();

        for (int i = 0; i < idx; i++, it++)
        {
        }

        return it;
    }

public:
    string getPermutation(int n, int k)
    {
        pow_init();

        string ans;

        for (int i = 1; i <= n; i++)
        {
            num.push_back(i);
        }

        int prt = 0;
        while (n > 0)
        {
            prt = ceil((double)k / (double)pown[--n]);
            k -= (prt - 1) * pown[n];
            ans += (num[prt] + '0');
            num.erase(get_vector_iterator(prt));
        }
        return ans;
    }
};

int main() 
{
    Solution s; 
    cout << s.getPermutation(3,3);
    return 0; 
}