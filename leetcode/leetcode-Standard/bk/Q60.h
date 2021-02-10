class Solution
{
private:
    /*int fun(int n)
    {
        int num = 1;
        int cnt = 0;

        for (cnt = 1; cnt <= n; i++)
        {
            num *= cnt;
        }

        return num;
    }*/
public:
    string getPermutation1(int n, int k)
    {
        string ans;
        /*int cnt = 0;
        const int TOT = fun(n);
        int tn = n;

        for (cnt = 0; cnt < n; cnt++)
        {
            if (k % n == 0)
            {
                ans += (k / n);
                k -= (k / n * n);
            }
        }*/

        for (int i = 1; i <= n; i++)
        {
            ans += (i + '0');
        }

        for (int i = 1; i < k; i++)
        {
            next_permutation(ans.begin(), ans.end());
        }
        
       // ans = "123";
        return ans;
        //return "213";
    }
};