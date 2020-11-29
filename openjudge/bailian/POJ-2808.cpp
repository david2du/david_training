#include <iostream>
using namespace std;

bool rd[10010];

int main()
{
    int l = 0, m = 0;

    cin >> l >> m;

    for (int i = 0; i < m; i++)
    {
        int stt = 0, end = 0;
        cin >> stt >> end;

        for (int j = stt; j <= end; j++)
        {
            rd[j] = true;
        }
    }

    int sum = 0;
    for(int i = 0; i <= l; i++)
    {
        if (!rd[i])
        {
            sum++;
        }
    }

    cout <<sum << endl;

    return 0;
}