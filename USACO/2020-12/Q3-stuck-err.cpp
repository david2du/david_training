#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    int index;
    int initR;
    int initC;
};

vector<Cow> cow[3];
bool east[64];
int ans[64];

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char status = 0;
        int r = 0, c = 0;

        cin >> status >> r >> c;

        cow[status == 'E'].push_back((Cow){i, r, c});
        cow[2].push_back((Cow){i, r, c});
        east[i] = (status == 'E');
    }

    /*for (int i = 0; i < cow[0].size(); i++)
    {
        bool inf = true;

        for (int j = 0; j < cow[1].size(); j++)
        {
            if ((cow[1][j].initR > cow[0][i].initR) && (cow[0][i].initC < cow[1][j].initC))
            {
                if ((cow[1][j].initR - cow[0][i].initR) > (cow[0][i].initC - cow[1][j].initC))
                {
                    inf = false;
                    ans[cow[0][i].index] = cow[1][j].initR - cow[0][i].initR;
                }
            }
        }

        if (inf)
        {
            ans[cow[0][i].index] = -1;
        }
    }
    for (int i = 0; i < cow[1].size(); i++)
    {
        bool inf = true;

        for (int j = 0; j < cow[0].size(); j++)
        {
            if ((cow[1][j].initR > cow[0][i].initR) && (cow[0][i].initC < cow[1][j].initC))
            {
                if ((cow[1][j].initR - cow[0][i].initR) > (cow[0][i].initC - cow[1][j].initC))
                {
                    inf = false;
                    ans[cow[0][i].index] = cow[1][j].initR - cow[0][i].initR;
                }
            }
        }

        if (inf)
        {
            ans[cow[0][i].index] = -1;
        }
    }*/
    fill(ans, ans + n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        const bool opp = (!east[i]);
        bool inf = true; // infinity
        for (unsigned int j = 0; j < cow[opp].size(); j++)
        {
            if (!opp)
            {
                if ((cow[opp][j].initR > cow[2][i].initR) && (cow[opp][j].initC <= cow[2][i].initC))
                {
                    if ((cow[opp][j].initR - cow[2][i].initR) > (cow[2][i].initC - cow[opp][j].initC))
                    {
                        inf = false;
                        ans[i] = min(ans[i], cow[opp][j].initR - cow[2][i].initR);
                        
                    }
                }
            }
            else
            {
                if ((cow[opp][j].initC > cow[2][i].initC) && (cow[opp][j].initR <= cow[2][i].initR))
                {
                    if ((cow[opp][j].initC - cow[2][i].initC) > (cow[2][i].initR - cow[opp][j].initR))
                    {
                        inf = false;
                        ans[i] = min(ans[i], cow[opp][j].initC - cow[2][i].initC);
                    }
                }
            }
        }

        if (inf)
        {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] != -1)
        {
            cout << ans[i] << endl;
        }
        else
        {
            cout << "Infinity" << endl;
        }
    }

    return 0;
}