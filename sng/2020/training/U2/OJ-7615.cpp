#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Stu
{
    int score;
    string name;
};

bool cmp(const Stu &A, const Stu &B)
{
     /*if (A.score != B.score)
     {
        return A.score > B.score;
     }
     return A.name < B.name;*/
     return (A.score != B.score) ? (A.score > B.score) : (A.name < B.name);
}

int main()
{
    int n = 0;
    Stu stu[32];
    
    //cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        //cin >> stu[i].name >> stu[i].score;
        scanf("%s%d", &stu[i].name, &stu[i].score);
    }
    
    sort(stu, stu + n, cmp);
    
    for (int i = 0; i < n; i++)
    {
        //cout << stu[i].name << " " << stu[i].score << endl;
        scanf("%s %d", &stu[i].name, &stu[i].score);
    }    
    
    //system("pause");
    return 0;
}
