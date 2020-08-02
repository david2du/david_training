#include<cstdio>
#include<windows.h>
#include<WinBase.h>
void gotoxy(int x,int y)
{    
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hout,pos);
}

int main()
{   
	int x=1, y=12, t,i = 0;
	
	int m =0, n = 0;
	
	for (m=0; m < 100; m++)
	{
		for (int n=0; n<127;n++)
		{
			printf("%c",n);
		}
	
		
	}

     
    /*for(x=2;x>1;x++)
    { 
	 	system("cls");
	 	for(int m=0; m< 79; m++)
	 		{
	 			 gotoxy(x, m);
				for(;i>=0;i++)
				{
		 			if(i>127)
					{
						i = 0;			
					};
					i++;
					system("cls");
					printf("%c",i);
					for(t=1;t<=99999999;t++); 
				};
			 
			 }
			
	 }*/
		
             
         
   getchar();    return 0;
}

