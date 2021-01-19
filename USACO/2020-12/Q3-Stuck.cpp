#include <bits/stdc++.h>
using namespace std;

struct Visit
{
    bool visit;
    int visit_index;
    int visit_step;
};

struct Cow
{
    int init_index_X;
    int init_index_Y;
    bool face_east;
};

Cow cow[64];

int crash(const int &index, const int &compare_index)
{
    if (cow[index].face_east)
    {
        if (cow[index].face_east == cow[compare_index].face_east)
        {
            if (cow[index].init_index_Y == cow[compare_index].init_index_Y)
            {
                return abs(cow[index].init_index_X - cow[compare_index].init_index_X);
            }
            return -1;
        }
        if (!((cow[index].init_index_Y >= cow[compare_index].init_index_Y) && (cow[index].init_index_X < cow[compare_index].init_index_X)))
        {
            return -1;
        }

        const int Crash_x = cow[compare_index].init_index_X, Crash_y = cow[index].init_index_Y;

        if ((Crash_x - cow[index].init_index_X) <= (Crash_y - cow[compare_index].init_index_Y))
        {
            return -1;
        }
        return Crash_x - cow[index].init_index_X;
    }
    else
    {
        if (cow[index].face_east == cow[compare_index].face_east)
        {
            if (cow[index].init_index_X == cow[compare_index].init_index_X)
            {
                return abs(cow[index].init_index_Y - cow[index].init_index_Y);
            }
            return -1;
        }
        if (!((cow[index].init_index_Y < cow[compare_index].init_index_Y) && (cow[index].init_index_X >= cow[compare_index].init_index_X)))
        {
            return -1;
        }

        const int Crash_x = cow[index].init_index_X, Crash_y = cow[compare_index].init_index_Y;

        if ((Crash_y - cow[index].init_index_Y) <= (Crash_x - cow[compare_index].init_index_X))
        {
            return -1;
        }
        return Crash_y - cow[index].init_index_Y;
    }

    return -1;
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c = 0;
        cin >> c >> cow[i].init_index_X >> cow[i].init_index_Y;
        cow[i].face_east = (c == 'E');
    }

    fill(step, step + n, INT_MAX);

    for (int i = k; i < n; i = (i + 1) % n)
    {
        int step = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                int t = crash(i, j);

                printf("i, j:%d, %d, return: %d\n", i, j, t);

                if (t != -1)
                {
                    step = min(step, t);
                }
            }
        }
        if (step == -1)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            cout << step << endl;
        }
    }

    return 0;
}