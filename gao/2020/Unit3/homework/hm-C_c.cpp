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
    char s[128];
    ll n = 0;
    ll nu = 0;
    ll i = 0, j = 0;

    scanf("%lld", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", s);

        if (strcmp(s, "Push") == 0)
        {
            ll pushn = 0;
            scanf("%lld", &nu);

            for (j = 0; j < nu; j++)
            {
                scanf("%lld", &pushn);

                enqueue(pushn);
            }
        }
        else if (strcmp(s, "Pop") == 0)
        {
            ll popn = 0;

            scanf("%lld", &nu);

            for (j = 0; j < nu; j++)
            {
                popn = dequeue();

                printf("%lld ", popn);

                if (popn == -1)
                {
                    break;
                }
            }

            printf("\n");
        }
        else if (strcmp(s, "Front") == 0)
        {
            printf("%lld\n", frontn());
        }
        else if (strcmp(s, "Size") == 0)
        {
            printf("%lld\n", size());
        }
        else
        {
            continue;
        }
    }

    return 0;
}