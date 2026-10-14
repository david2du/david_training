#include <stdio.h>
#include <string.h>

char word[1010][1010];
int sz[1010];
int cnt;
int s[1010];
int cnt2;

int main()
{
    char c = 0;
    int wd = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (!wd)
            {
                wd = 1;
                cnt++;
                s[cnt2++] = -1;
            }
            word[cnt][sz[cnt]++] = c;
        }
        else
        {
            wd = 0;
            s[cnt2++] = (int)c;
        }
    }

    int j = cnt;
    for (int i = 0; i < cnt2; ++i)
    {
        if (s[i] != -1)
            putchar((char)s[i]);
        else
        {
            for (int k = 0; k < sz[j]; ++k)
            {
                putchar((char)word[j][k]);
            }
            j--;
        }
    }

    return 0;
}