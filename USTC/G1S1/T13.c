#include <stdio.h>

int card[4][15];

int main()
{
    while (1)
    {
        char s[5];
        scanf ("%s", s);
        if (s[0] == '0')
            break;
        int c = 0;
        if (s[0] == 'D')
            c = 0;
        else if (s[0] == 'C')
            c = 1;
        else if (s[0] == 'H')
            c = 2;
        else
            c = 3;
        int num = 0;
        if (s[1] >= '0' && s[1] <= '9')
            num = s[1] - '0';
        else
        {
            if (s[1] == 'T')
                num = 10;
            else if (s[1] == 'J')
                num = 11;
            else if (s[1] == 'Q')
                num = 12;
            else if (s[1] == 'K')
                num = 13;
            else
                num = 14;
        }
        card[c][num] = 1;
        if (num == 14)
            card[c][1] = 1; 
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            int flag = 1;
            for (int k = 0; k < 5; ++k)
                if (!card[i][k + j])
                {
                    flag = 0;
                    break;
                }
            if (flag)
            {
                printf("straight flush\n");
                return 0;
            }
        }
    }

    for (int j = 1; j <= 13; ++j)
    {
        int flag = 1;
        for (int i = 0; i < 4; ++i)
        {
            if (!card[i][j])
                flag = 0;
        }
        if (flag)
        {
            printf("four of a kind\n");
            return 0;
        }
    }

    int two = 0, three = 0;
    for (int j = 1; j <= 13; ++j)
    {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
            cnt += card[i][j];
        if (cnt == 2)
            two = 1;
        else if (cnt == 3)
            three = 1;
        if (two && three)
        {
            printf("full house\n");
            return 0;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= 13; ++j)
            cnt += card[i][j];
        if (cnt == 5)
        {
            printf("flush\n");
            return 0;
        }
        if (cnt)
            break;
    }

    for (int j = 1; j <= 10; ++j)
    {
        int f2 = 1;
        int cnt = 0;
        for (int k = 0; k < 5; ++k)
        {
            int c = 0;
            for (int i = 0; i < 4; ++i)
            {
                c += card[i][j + k];
            }
            if (c >= 2)
            {
                f2 = 0;
                break;
            }
            if (c == 1)
            {
                cnt++;
            }
        }
        if (!f2)
            break;
        if (cnt == 5)
        {
            printf("straight\n");
            return 0;
        }
    }

    for (int j = 1; j <= 13; ++j)
    {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
            cnt += card[i][j];
        if (cnt >= 3)
        {
            printf("three of a kind\n");
            return 0;
        }
    }

    int pr = 0;
    for (int j = 1; j <= 13; ++j)
    {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
            cnt += card[i][j];
        if (cnt == 2)
            pr++;
    }
    if (pr == 2)
    {
        printf("two pairs\n");
        return 0;
    }

    for (int j = 1; j <= 13; ++j)
    {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
            cnt += card[i][j];
        if (cnt == 2)
        {
            printf("pair\n");
            return 0;
        }
    }

    printf("high card\n");
    
    return 0;
}
