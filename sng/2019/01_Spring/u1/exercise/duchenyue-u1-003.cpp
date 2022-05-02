#include<stdio.h>
int main()
{
	int cA4 = 0, cA5 = 0, sA4 = 0, sA5 = 0;
	int a = 0, b = 0, c = 0, d = 0;
	
	a = 297;
	b = 210;
	c = 210;
	d = 148;
	 
	cA4 = ( a + b) * 2;
	cA5 = ( c + d) * 2;
	
	sA4 = a * b;
	sA5 = c * d;
	
	printf("  A4	:\n");
	printf("  \n");
	printf("	C = ");	
	printf("%d\n",cA4);
	printf(	"	S = ");
	printf("%d\n",sA4);
	
	printf("  A5	:\n");
	printf("  \n");
	printf("	C = ");	
	printf("%d\n",cA5);
	printf(	"	S = ");
	printf("%d\n",sA5);
		
	getchar();
	
	return(0);	
}
