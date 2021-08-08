#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sta[1000010], top;

void push(ll x)
{
    sta[top++] = x;
}

ll pop()
{
    if (top == 0)
    {
        return -1;
    }

    return sta[--top];
}

ll Top()
{
    if (top == 0)
    {
        return -1;
    }

    return sta[top - 1];
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
        else if (op[0] == 'T')//"Top"
        {
            printf("%lld\n", Top());
        }
        else if (op[0] == 'S')
        {
            printf("%lld\n", top);
        }
        else
        {
            continue;
        }
    }

    return 0;
}