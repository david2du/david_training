#include <iostream>
using namespace std;

struct Stu
{
    int age;
    string name;

    Stu operator+(Stu b)
    {
        return (Stu){age + b.age, name + b.name};
    }
    Stu operator-(Stu b)
    {
        return (Stu){age - b.age, name + b.name};
    }
    Stu operator*(Stu b)
    {
        return (Stu){age * b.age, name + b.name};
    }
    Stu operator/(Stu b)
    {
        return (Stu){age / b.age, name + b.name};
    }
    Stu operator%(Stu b)
    {
        return (Stu){age % b.age, name + b.name};
    }

    

    bool operator>(Stu b)
    {
        //return (age > b.age);
        return name > b.name;
    }
    bool operator<(Stu b)
    {
        //return (age < b.age);
        return name < b.name;
    }
    bool operator==(Stu b)
    {
        //return (age == b.age);
        return (name.compare(b.name) == 0);
    }
};

int main()
{
    Stu andy = (Stu){10, "andy"};
    Stu david = (Stu){20, "david"};

    Stu t = andy + david;
    cout << t.name << endl
         << t.age << endl;

    t = andy % david;
    cout << t.name << endl
         << t.age << endl;

    t = andy / david;
    cout << t.name << endl
         << t.age << endl;

    return 0;
}
