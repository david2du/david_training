#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int x;
    Node *nxt;
} Node;

Node *hd = NULL, *tl = NULL;

Node *del(Node *x)
{
    Node *nxt = x->nxt;
    free(x);

    return nxt;
}

void push(int x)
{
    Node *p = malloc(sizeof(Node));
    Node *ptr = hd;
    while (ptr != NULL)
    {
        if ((ptr->x) > x)
            break;
    }
}

int main()
{
    int n = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        scanf("%d", &x);
        push(x);
    }

    while ((hd->nxt != NULL))
    {
        printf("%d", hd->x);
        hd = del(hd);
    }

    return 0;
}