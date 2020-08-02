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
	ifstream f1in("status.in");
	ifstream f2in("secret_number.txt");
	ofstream f1out("secret.out");
	ofstream f2out("secret_number.txt");
	
    for (unsigned int i = 0; i < init.size(); ++i)
    {
        if ((init[i] >= 'a') && (init[i] <= 'z'))
        {
            f1out << (init[i] - 'a');
        }
        else if ((init[i] >= 'A') && (init[i] <= 'Z'))
        {
            f1out << "C" << (init[i] - 'A');
        }
        else if ((init[i] >= '0') && (init[i] <= '9'))
        {
            f1out << "N" << (init[i] - '0');
        }
        else if (init[i] == ' ')
        {
            f1out << " ";
            continue;
        }
        else
        {
            f1out << init[i];
        }

        if ((i < (init.size() - 1)) && (init[i + 1] != ' ') && (i < (init.size() - 1)))
        {
            f1out << "-";
        }
    }
}

int main(int argc, char const *argv[])
{
	string s;
	int status = 0;
	
	ifstream f1in("status.in");
	ifstream f2in("secret_number.txt");
	ofstream f1out("secret.out");
	ofstream f2out("secret_number.txt");
	ofstream f3out("status.in");
	
	f1in >> status;
	if (status > 0)
	{
		printf("SECRET NUMBER:");
		textcolor(0);
		cin >> s;
		
		string SEC;
		f2in >> SEC;
		if (s != SEC)
		{
			return 0;
		}
	}
	else
	{
		printf("It is your first time to use it. \n Input SECRET NUMBER:");
		cin >> s;
		
		f2out << s;
		f3out << 1;
	}
	
	textcolor(15);
	
	system("cls");
	
    string init;

    while (getline(cin, init))
    {
        if ((init != "AR") && (init != "AS") && (init != "K AS") && (init != "SK"))
        {
            DP(init);
        }
        else
        {
            f1out << endl << endl << "status : ";
            DP(init);
            break;
        }
        f1out << endl;
    }

    return 0;
}
