#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define NONE "\033[0m"
#define GREEN "\033[44;32m"
#define RED "\033[47;31m"

vector<char> vch;
vector<char> vuc;
int gNum;

void color(int idx, bool right)
{
    if (right == true)
    {
        printf(GREEN, vuc[idx], NONE);
    }
    else
    {
        printf(RED, vuc[idx], NONE);
    }
}

void build()
{
    gNum = rand() % 51 + 30;
    cout << "Please Type " << gNum << ": ";

    for (int i = 0; i < gNum; i++)
    {
        char c = 0;

        c = rand() % 95 + 32;
        vch.push_back(c);
        cout << c;
    }

    cout << "(end)" << endl
         << "Type :";
}

void judge()
{
    cout << endl;

    for (int i = 0; i < gNum; i++)
    {
        bool right = (vuc[i] == vch[i]);

        color(i, right);
    }
}

void get()
{
    for (int i = 0; i < gNum; i++)
    {
        char c = 0;

        //c = fgetc(stdin);
        scanf("%c", &c);
        vuc.push_back(c);
    }
    judge();
}

void reset()
{
    while (vch.size() != 0)
    {
        vch.pop_back();
    }

    while (vuc.size() != 0)
    {
        vch.pop_back();
    }

    gNum = 0;
}

int main()
{
    int round = 0;

    srand(time(0));

    cout << "How Many Rounds Do You Want : ";
    cin >> round;

    for (int i = 0; i < round; i++)
    {
        cout << "' (end)'for ending" << endl;
        reset();

        build();
        get();
    }

    return 0;
}