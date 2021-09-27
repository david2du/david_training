#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int num[50010];

priority_queue<int> q;
/*

1
0
*/
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

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        while ((!q.empty()) && (q.top() > num[i]))
        {
            q.pop();
        }
        if ((q.empty()) || (q.top() != num[i]))
        {
            q.push(num[i]);
            ans++;
        }
    }

    cout << ans - 1 << endl;

    return 0;
}