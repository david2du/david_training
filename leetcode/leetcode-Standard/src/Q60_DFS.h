#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool vst[16];

    int mn; // member n
    int mk; // member k
    vector<string> v;
    //int cnt;
    /**
     * @return Return True: Found permutation No.k, Return False: Not found.
    */
    bool dfs(int last_step, string last, int chosen_num)
    {
        last_step++;
        last += (chosen_num + '0');
        vst[chosen_num] = true;
        if (last_step == mn)
        {
            v.push_back(last);
            if (v.size() == mk)
            {
                return true;
            }
            return false;
        }

        for (int i = 1; i <= mn; i++)
        {
            if (!vst[i])
            {
                if (dfs(last_step, last, i))
                {
                    return true;
                }
            }
        }

        vst[chosen_num] = false;
        return false;
    }

    /*void dfs(int choosed, string last, int step)
    {
        if (choosed != 0)
        {
            last += (choosed + '0');
        }
        if (step == num)
        {
            v.push_back(last);
            return; 
        }step++;
        for (int i = 1; i <= num; i++)
        {
            if (!vst[i])
            {
                vst[i] = true;
                dfs(i, last, step);                
                vst[i] = false;
            }
        }

        
    }*/
public:
    Solution() 
    {
        mk = 0; 
        mn = 0; 
        fill(vst, vst + 16, false);
        vector<string> v1;
        v = v1;
        std::cout <<"Solution constructor"<< endl;
    }
    string getPermutation(int n, int k)
    {
       
        mk = k;
        mn = n;
        string s;

        //dfs(0, s, 0);
        for (int i = 1; i <= mn; i++)
        {
            dfs(0, s, i);
        }
        if (v.size() >= k)
        {
            return v[k - 1];
        }

        else
        {
            return "";
        }
    }
};


int main() 
{
    Solution s; 
    cout <<s.getPermutation(3, 3);
}
