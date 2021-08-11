#include <iostream>
#include <string>
using namespace std;

/*char graph[7010][110][110];

long long n, m;

long long dif[110][110];
long long diff[110];

void dis(long long a, long long b)
{
    long long ans = 0;

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m;j++)
        {
            ans += abs(graph[a][i][j] - graph[b][i][j]);
        }
    }

    dif[a][b] = ans;
    dif[b][a] = ans;
    diff[a] += ans;
    diff[b] += ans;
}

long long main(long long argc, char const *argv[])
{
    long long k = 0, s = 0;

    freopen("drawing1.in", "r", stdin);
    freopen("drawing.out", "w", stdout);

    cin >> n >> m >> k >> s;

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (long long i = 1; i <= k; i++)
    {
        long long a = 0, b = 0, c = 0, d = 0;
        char ch = 0;

        cin >> a >> b >> c >> d >> ch;

        for (long long j = a; j <= c; j++)
        {
            for (long long t = b; t <= d; t++)
            {
                graph[i][j][t] = ch;
            }
        }
    }

    for (long long i = 1; i < k; i++)
    {
        for(long long j = i + 1; j <= k; j++)
        {
            dis(i, j);
        }
    }

    long long min = LLONG_MAX;
    long long minidx = 0;
    for (long long i = 1; i <= k; i++)
    {
        if (min > diff[i])
        {
            min = diff[i];
            minidx = i;
        }
    }

    cout << min << " " << minidx << endl;

    return 0;
}*/

string graph[7010][110];

long long n, m;

long long diff[7010];

void dis(long long a, long long b)
{
    long long ans = 0;

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            ans += abs(graph[a][i][j] - graph[b][i][j]);
        }
    }
    diff[a] += ans;
    diff[b] += ans;
}

int main(int argc, char const *argv[])
{
    long long k = 0, s = 0;

    freopen("drawing.in", "r", stdin);
    freopen("drawing.out", "w", stdout);

    cin >> n >> m >> k >> s;

    for (long long i = 1; i <= n; i++)
    {
        cin >> graph[0][i];
    }
    for (long long i = 1; i <= k; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            graph[i][j] = graph[0][j];
        }
    }
    for (long long i = 1; i <= k; i++)
    {
        long long a = 0, b = 0, c = 0, d = 0;
        char ch = 0;

        cin >> a >> b >> c >> d >> ch;

        for (long long j = a; j <= c; j++)
        {
            for (long long t = b; t <= d; t++)
            {
                graph[i][j][t] = ch;
            }
        }
    }

    for (long long i = 1; i < k; i++)
    {
        for (long long j = i + 1; j <= k; j++)
        {
            dis(i, j);
        }
    }

    long long min = LLONG_MAX;
    long long minidx = 0;
    for (long long i = 1; i <= k; i++)
    {
        //cout <<diff[i] << endl;
        if (min > diff[i])
        {
            min = diff[i];
            minidx = i;
        }
    }

    cout << min << " " << minidx << endl;

    return 0;
}