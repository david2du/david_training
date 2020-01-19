#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
float sta[MAXN];
int top = 0;

bool empty()
{
    return top == 0;
}

bool full()
{
    return top == MAXN;
}

int size()
{
    return top;
}

void push(float n)
{
    sta[top++] = n;
}

float pop()
{
    return sta[--top];
}

const int SMAX = 10000;
string inputStr;
char str[SMAX];

void opr()
{
    char * ptoken; 
    float f1 = 0, f2 = 0, f3 = 0; 

    getline(cin, inputStr);
    strcpy(str, inputStr.c_str());
    ptoken = strtok(str, " ");

    while(ptoken != NULL)
    {
        if (strcmp(ptoken, "+") == 0)
        {
            f1 = pop();
            f2 = pop();
            f3 = f2 + f1;

            push(f3);
        }
        else if (strcmp(ptoken, "-") == 0)
        {
            f1 = pop();
            f2 = pop();
            f3 = f2 - f1;

            push(f3);
        }
        else if (strcmp(ptoken, "*") == 0)
        {
            f1 = pop();
            f2 = pop();
            f3 = f2 * f1;

            push(f3);
        }
        else if (strcmp(ptoken, "/") == 0)
        {
            f1 = pop();
            f2 = pop();
            f3 = f2 / f1;

            push(f3);
        }
        else
        {
            push(atof(ptoken));
        }

        ptoken = strtok(NULL, " ");       
    }

    printf("%0.6f", sta[top - 1]);
}

int main()
{
    opr();

    return 0;
}