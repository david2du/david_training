#include <iostream>
#include <set>
using namespace std;

int stn[7];
int wb[7];

set<int> st;

inline void dfs(int nowdep, int ans, int num)
{
    ans += (num * wb[nowdep]);
    st.insert(ans);

    if (nowdep == 6)
    {
        return;
    }

    nowdep++;
    for (int i = 0; i <= stn[nowdep]; i++)
    {
        dfs(nowdep, ans, i);
    }
}

int main(int argc, char const *argv[])
{
    cin >> stn[1] >> stn[2] >> stn[3] >> stn[4] >> stn[5] >> stn[6];
    wb[1] = 1;
    wb[2] = 2;
    wb[3] = 3;
    wb[4] = 5;
    wb[5] = 10;
    wb[6] = 20;

    dfs(0, 0, 0);
    cout << "Total=" << st.size() - 1 << endl;

    return 0;
}