#include <bits/stdc++.h>
using namespace std;

void opr(string &A, string &B)
{
    for (int i = 0; i < max(A.size(), B.size()); i++)
    {
        if (A[i] == B[i])
        {
            A.erase(i, 1);
            B.erase(i, 1);
        }
    }

    bool flag = false;
    for (int i = 1; i < max(A.size(), B.size()); i++)
    {
        if (B[i - 1] == A[i])
        {
            B.erase(i - 1, 1);
            flag = true;
        }
    }

    if (!flag)
    {
        for (int i = 1; i < max(A.size(), B.size()); i++)
        {
            if (A[i - 1] == B[i])
            {
                A.erase(i - 1, 1);
                break;
            }
        }
    }

    for (int i = 0; i < max(A.size(), B.size()); i++)
    {
        if (A[i] == B[i])
        {
            A.erase(i, 1);
            B.erase(i, 1);
        }
    }
}

void pcs(string &A, string &B)
{
    if (A.size() <= B.size())
    {
        int id = 0;
        while (find_if(A.begin(), A.end(), [B, &id](auto x)
                       { return x == B[id++]; }) != A.end())
        {
            opr(A, B);
        }
    }
    else
    {
        int id = 0;
        while (find_if(B.begin(), B.end(), [A, &id](auto x)
                       { return x == A[id++]; }) != B.end())
        {
            opr(A, B);
        }
    }
}

int ASF(string A, string B)
{
    int base = 1;
    if (A.size() < B.size())
    {
        swap(A, B);
        base = -1;
    }

    int res = 0, id = 0;

    for_each(B.begin(), B.end(), [A, &res, &id](auto x)
             { 
                 res += (x - A[id]);
                 id++; });

    return res * base + (A.size() - B.size());
}

int main(int argc, char const *argv[])
{
    string s1, s2;

    cin >> s1 >> s2;

    pcs(s1, s2);
    cout << ASF(s1, s2) << endl;

    return 0;
}
