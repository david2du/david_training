#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void textcolor(int c)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

/*
    Decrypt Part
*/
void DP(const string &init)
{
    for (unsigned int i = 0; i < init.size(); ++i)
    {
        if ((init[i] >= 'a') && (init[i] <= 'z'))
        {
            printf("%d", init[i] - 'a');
        }
        else if ((init[i] >= 'A') && (init[i] <= 'Z'))
        {
            printf("C%d", init[i] - 'A');
        }
        else if ((init[i] >= '0') && (init[i] <= '9'))
        {
            printf("N%d", init[i] - '0');
        }
        else if (init[i] == ' ')
        {
            printf(" ");
            continue;
        }
        else
        {
            printf("%d", init[i]);
        }

        if ((i < (init.size() - 1)) && (init[i + 1] != ' ') && (i < (init.size() - 1)))
        {
            printf("-");
        }
    }
}

int main(int argc, char const *argv[])
{
	const string SEC = "secret2david";
	string s;
	
	printf("SECRET NUMBER:");
	textcolor(0);
	cin >> s;
	textcolor(15);
	if (s != SEC)
	{
		return 0;
	}
	
	system("cls");
	
    string init;

    freopen("secret.out", "w", stdout);

    while (getline(cin, init))
    {
        if ((init != "AR") && (init != "AS") && (init != "K AS") && (init != "SK"))
        {
            DP(init);
        }
        else
        {
            printf("\n\n\nStatus : ");
            DP(init);
            break;
        }
        printf("\n");
    }

    return 0;
}
