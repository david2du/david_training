#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int x;
    struct Node *nxt;
    struct Node *prev;
} Node;

Node *hd = NULL, *tail = NULL;

Node *del(Node *x)
{
    if (x->prev != NULL)
        (x->prev)->nxt = x->nxt;
    else
        hd = x->nxt;

    if (x->nxt != NULL)
        (x->nxt)->prev = x->prev;
    else
        tail = x->prev;
    Node *nxt = x->nxt;
    free(x);

    return nxt;
}

void push(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->x = x;

    if (hd == NULL)
    {
        p->prev = NULL;
        p->nxt = NULL;
        hd = p;
        tail = p;
        return;
    }
    if (hd->x > x)
    {
        hd->prev = p;
        p->nxt = hd;
        p->prev = NULL;
        hd = p;
        return;
    }
    Node *ptr = hd;
    while (ptr != NULL)
    {
        if ((ptr->x) > x)
            break;
        ptr = ptr->nxt;
    }
    if (ptr == NULL)
    {
        p->nxt = NULL;
        p->prev = tail;
        tail->nxt = p;
        tail = p;
    }
    else
    {
        p->nxt = ptr;
        p->prev = ptr->prev;
        (ptr->prev)->nxt = p;
        ptr->prev = p;
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

    while ((hd != NULL))
    {
        printf("%d\n", hd->x);
        hd = del(hd);
    }

    return 0;
}