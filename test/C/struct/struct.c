#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node;
typedef struct Node * List;

struct Node
{
    List nxt;
    int val;
};


void insert()
{
    List p = (List)malloc(sizeof(struct Node));
    List m = (List)calloc(1, sizeof(struct Node));

    printf("%d\n", p->nxt);
    printf("%d\n", m->nxt);
}

void del(List A)
{

}

int main()
{
    printf("%d\n", sizeof(struct Node));
    insert();

    return 0;
}