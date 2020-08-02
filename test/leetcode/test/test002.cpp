#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        return sen(str);
    }
    string sen(string str)
    {
        unsigned int i = 0; 
        for (i = 0; i < str.size(); i++)
        {
            if (str[i] >='A' && str[i] <= 'Z')
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

    cout << s.toLowerCase("Hello")<< endl; 

    return 0;
}