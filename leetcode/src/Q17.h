#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    map<char, vector<string>> letr = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}}; // letter

    string digit;

public:
    /*vector<string> dfs(vector<string> last, char num, int idx)
    {
        vector<string> v;

        if (idx == digit.size())
        {
            return last;
        }

        for (int i = 0; i < letr[num].size(); ++i)
        {
            v.push_back(letr[num][i]);
            for (int j = 0; j < last.size(); ++j)
            {
                v.push_back(last[j] + letr[num][i]);
            }
        }

        if ((idx + 1) == digit.size())
        {
            return v;
        }
        return dfs(v, digit[++idx], idx);
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> v;
        vector<string> tmp;

        digit = digits;

        v = dfs(tmp, digit[0], 0);

        return v;
    }*/
};