#include <iostream>
using namespace std;
const int NMAX = 100; 

struct Stu 
{
    string info; 
}; 

Stu students[NMAX];

struct Node 
{
    Stu stu; 
    int next; 
    int pre; 
};

Node node[NMAX];


int head ;
int rear;

void buildLink(Stu mystus[] , int size)
{
    head = 0; 
    int p  = head;  
    for (int i = 0; i < size; i ++)
    {
        node[p].stu = mystus[i];
        node[p].next = -1; 
        if (p > 0)
        {
            node[p].pre = p -1; 
            node[p-1].next = p; 
        }
        else
        {
            node[p].pre = -1; 
        }  
        p++;       
    }
    rear = size -1; 

}

void print() 
{
    int p = head;
    Stu s;  
    do
    {
        cout << node[p].stu.info<<endl; 
        p = node[p].next; 
    }
    while(p != -1);

}

void reversePrint() 
{
    int p = rear;
    Stu s;  
    do
    {
        cout << node[p].stu.info<<endl; 
        p = node[p].pre; 
    }
    while(p != -1);

}

int main() 
{
    int n = 0; int i = 0; 
    cout <<"please input:"<<endl;
    cin >> n; 
    for ( i = 0; i < n; i++)
    {
        cin >> students[i].info;
    }

    buildLink(students, n);
    print(); 
    reversePrint();


    return 0; 
}