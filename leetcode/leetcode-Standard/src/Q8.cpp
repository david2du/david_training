#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long long ans = 0LL;

        int i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                break;
            }
        }

        if (i == s.size())
        {
            return ans;
        }

        bool neg = false; // negative

        if (s[i] == '+' || s[i] == '-')
        {
            neg = (s[i] == '-');
            i++;
        }

        for (; i < s.size() && (s[i] >= '0') && (s[i] <= '9'); i++)
        {
            ans *= 10;
            if (neg)
            {
                ans -= (s[i] - '0');
            }
            else
            {
                ans += (s[i] - '0');
            }

            if (ans <= INT_MIN)
            {
                return INT_MIN;
            }
            if (ans >= INT_MAX)
            {
                return INT_MAX;
            }
        }

        return ans;
    }
};