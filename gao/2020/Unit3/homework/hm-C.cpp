#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 10010;
ll q[M];
ll front, rear;

bool empty()
{
    return (front == rear);
}

bool full()
{
    return ((rear + 1) % M == front);
}

ll frontn()
{
    if (empty() == true)
    {
        return -1;
    }

    return q[front];
}

ll size()
{
    return ((rear - front + M) % M);
}

void enqueue(ll x)
{
    if (full() == true)
    {
        return;
    }

    q[rear++] = x;
    rear %= M;
}

ll dequeue()
{
    if (empty() == true)
    {
        return -1;
    }

    ll ans = q[front++];
    front %= M;

    return ans;
}

int main()
{
    string s;
    ll n = 0;
    ll nu = 0;
    ll i = 0, j = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> s;

        if (s.compare("Push") == 0)
        {
            ll pushn = 0;
            cin >> nu;

            for (j = 0; j < nu; j++)
            {
                cin >> pushn;

                enqueue(pushn);
            }
        }
        else if (s.compare("Pop") == 0)
        {
            ll popn = 0;

            cin >> nu;

            for (j = 0; j < nu; j++)
            {
                popn = dequeue();

                cout << popn << " ";

                if (popn == -1)
                {
                    break;
                }
            }

            cout << endl;
        }
        else if (s.compare("Front") == 0)
        {
            cout << frontn() << endl;
        }
        else if (s.compare("Size") == 0)
        {
            cout << size() << endl;
        }
        else
        {
            continue;
        }
    }

    return 0;
}