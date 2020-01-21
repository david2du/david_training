#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll que[1000010], front, rear;

void push(ll x)
{
    que[rear++] = x;
}

ll pop()
{
    if (front == rear)
    {
        return -1;
    }

    return que[front++];
}

ll Front()
{
    if (front == rear)
    {
        return -1;
    }

    return que[front];
}

int main()
{
    int n, c;
    ll x;
    char op[10];

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", op);

        if ((op[0] == 'P') && (op[1] == 'u'))//"Push"
        {
            scanf("%d", &c);

            for (int i = i; i <= c; i++)
            {
                scanf("%lld", &x);
                push(x);
            }
        }
        else if ((op[0] == 'P') && (op[1] == 'o'))//"Pop"
        {
            scanf("%d", &c);
            for (int i = 1; i <= c; i++)
            {
                printf("%lld ", pop());
            }
            printf("\n");
        }
        else if (op[0] == 'F')//"Front"
        {
            printf("%lld\n", Front());
        }
        else if (op[0] == 'S')
        {
            printf("%lld\n", rear - front);
        }
        else
        {
            continue;
        }
    }

    return 0;
}