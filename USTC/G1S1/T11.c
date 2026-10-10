#include <stdio.h>

int main()
{
    char s[110];

    scanf("%[^\n]", s);

    char *pa = s;
    char *pb = s;

    while ((*pb) != '\0')
        pb++;
    pb--;
    while (pa != pb && (pa + 1) != pb)
    {
        if ((*pa) != (*pb))
        {
            printf("No\n");
            return 0;
        }
        pb--;
        pa++;
    }
    printf("Yes\n");

    return 0;
}