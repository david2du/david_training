#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int num[50010];

priority_queue<int> q;

int main(int argc, char const *argv[])
{
    int n = 0, w = 0;

    //freopen("skyline.in", "r", stdin);
    //freopen("skyline.out", "w", stdout);

    cin >> n >> w;

    num[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = 0;

        cin >> x >> num[i];
    }

    num[n + 1] = 0;

    int ans = 0;
    //q.push(num[0]);
    for (int i = 1; i <= (n + 1); i++)
    {
        if ((q.empty()) || (num[i] > q.top()))
        {
            q.push(num[i]);
        }
        else
        {
            if (q.empty())
            {
                ans++;
            }
            while ((q.top() > num[i]) && (!q.empty()))
            {
                //cout << q.top() << endl;
                q.pop();
                ans++;
            }
            //cout << endl;
            
        }
    }

    cout << ans << endl;

    return 0;
}