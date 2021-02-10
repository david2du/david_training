
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    vector<string> v;
    long long num;
    int left_num, right_num;
    void dfs(bool left, string last, long long last_parenthesis_num)
    {
        if (left)
        {
            if ((left_num + 1) > (num / 2))
            {
                return;
            }
            else
            {
                ++left_num;
                last = last + "(";
            }
        }
        else
        {
            if (((right_num + 1) > (num / 2)) || ((right_num + 1) > left_num))
            {
                return;
            }
            else
            {
                ++right_num;
                last = last + ")";
            }
        }

        if (last_parenthesis_num + 1 == num)
        {
            v.push_back(last);
            return;
        }

        int ln = left_num, rn = right_num;

        dfs(true, last, last_parenthesis_num + 1);
        left_num = ln;
        right_num = rn;
        dfs(false, last, last_parenthesis_num + 1);
        left_num = ln;
        right_num = rn;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        num = 0;
        left_num = 0;
        right_num = 0;
        //Solution();
        //~Solution();

        if (n <= 0)
        {
            return v;
        }
        num = 2 * n;

        string s;
        dfs(true, s, 0);

        return v;
    }
};

