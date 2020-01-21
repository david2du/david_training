#include <iostream>
using namespace std;
const int NMAX = 100;  
const int QMAX=NMAX * NMAX + 1; 
 

struct  Node 
{
    int x; 
    int y; 
    int color;
}; 


Node  que[QMAX];

int front ; 
int rear; 

bool isEmpty()
{
    return rear == front;  
}

bool isFull () 
{
    return (rear + 1)%QMAX == front; 
};

void  enqueue(Node  a)
{
    que[rear++] = a; 
    rear %= QMAX; 
};

Node  dequeue() 
{ 
    Node q = que[front++];
    front %= QMAX; 
    return q; 

};

int  size() 
{
    return (QMAX + rear - front) % QMAX; 
};




Node gQi[NMAX][NMAX];
bool gMap[NMAX][NMAX];

const int BLACK = 1; 
const int WHIHE = 0; 

int gRow;
int gCol;


int dir[4][2] ={
    -1, 0,
    1, 0, 
    0, -1, 
    0, 1
};

void fill4Pass(Node q)
{
    int x , y;
    int i, j; 
    for (i = 0; i < 4; i++)
        {
            x = q.x + dir[i][0];
            y = q.y + dir[i][1];
            if (x <0 || x > gRow || y <0 || y >gCol)
                continue;
            if (gQi[x][y].color == BLACK && !gMap[x][y] )
                enqueue(gQi[x][y]); 
        } 



}

int gBlocks ;
void mark4Pass()
{
    Node qi ;
    int x, y;  

    while(!isEmpty())
    {
         qi = dequeue();
         x = qi.x; 
         y  = qi. y; 
         gMap[x][y] = true; 

         fill4Pass(qi);
    }
    gBlocks ++;

};



int main()
{
    cin >> gRow >> gCol;
    int i, j;
    for (i = 0; i < gRow; i++)
        for (j = 0; j < gCol; j++)
        {
            cin >> gQi[i][j].color;
            gQi[i][j].x = i; 
            gQi[i][j].y = j; 
        }
    
    //find the first black
    for (i = 0 ; i < gRow; i++)
        for (j = 0; j < gCol; j++)
            {
                // find one root black chess && not visited.
                if( gQi[i][j].color== BLACK && !gMap[i][j])
                {
                    //gMap[i][j] = true;
                    enqueue(gQi[i][j]);
                    mark4Pass();
                }
            }
    cout << gBlocks <<endl; 
}