#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, d = 0;

    for (a = 1; a < 10; ++a)
    {
        for (int b = 0; b < 10; ++b)
        {
            if (b == a)
            {
                continue;
            }

            for (int c = 0; c < 10; c++)
            {
                if ((c == a) || (c == b))
                {
                    continue;
                }

                for (int d = 0; d < 10; ++d)
                {
                    if ((d == a) || (d == b) || (d == c))
                    {
                        continue;
                    }

                    if ((a * 1000 + b * 100 + c * 10 + d) * 9 ==
                        (d * 1000 + c * 100 + b * 10 + a))
                    {
                        cout << (a * 1000 + b * 100 + c * 10 + d) << endl;
                        cout << b << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}