#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;

int x = 0, y, kb, step;
int xo = 4, yo = 5;
int qi[8][7] = {0};

void gotoxy(int x, int y)
{
  HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ʵ�������
  COORD pos;                                     //��ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(hout, pos);
}

void textcolor(int c)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, c);
}

void printQi(int x, int y, int color)
{
    gotoxy(10 + x * 2, y);
    //gottoxy(10 + x *2, 5 + y *2);
  //textcolor(13);
  textcolor(color);
  putchar(2);
}
void clearQi(int x, int y)
{
  gotoxy(10 + x * 2, y);
  putchar(32);
}

const int RED = 1;
const int YELLOW = 2;
const int RED_COLOUR = 12;
const int YELLOW_COLOR = 6
;

int win()
{
  return RED;
}

int main()
{

  system("chcp 437>nul."); //�޸ĵ�ǰcmd���ڴ���ҳ
  system("color a");

  x = 11;
  y = 6;

  // x=0;y=0;
  gotoxy(14, 3);
  printf("BING GAME \n");
  gotoxy(x, y + 0);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 187);
  gotoxy(x, y + 1);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
  gotoxy(x, y + 2);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
  gotoxy(x, y + 3);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
  gotoxy(x, y + 4);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
  gotoxy(x, y + 5);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
  gotoxy(x, y + 6);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
  gotoxy(x, y + 7);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
  gotoxy(x, y + 8);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
  gotoxy(x, y + 9);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
  gotoxy(x, y + 10);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
  gotoxy(x, y + 11);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
  gotoxy(x, y + 12);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 188);

  x = xo;
  y = yo;
  printQi(x, y, 2);

  while (1)
  {
    if (kbhit()) //判别键盘是否有键按下
    {
      clearQi(x, y);
      kb = getch(); //接收一个按键的代码

      if (kb == 27)
        exit(0); //是ESC键则退出游戏

      if (kb == 77) //向前进一格
      {
        if (x < 7)
          x++;
        printQi(x, y, 2);
       }
      if (kb == 75) //向后退一格
      {
        if (x > 1)
          x--;
        printQi(x, y, 2);
      }
      if (kb == 13)
      {
        while (y < 16 && (qi[x][y + 2] == 0))
        {
          y = y + 2;
        }
        step++;
        qi[x][y] = step % 2 + 1;
        if (qi[x][y] == RED)
        {
          printQi(x, y, RED_COLOUR);
        }

        else
        {
          printQi(x, y, YELLOW_COLOR);
        }
        x = xo, y = yo;
        printQi(x, y, 2);
      }
        Sleep(200);

    }
    // gotoxy(10+x*2,y); putchar(2);Sleep(200);  //新位置上显示棋子
  }

  getchar();
  return 0;
}
