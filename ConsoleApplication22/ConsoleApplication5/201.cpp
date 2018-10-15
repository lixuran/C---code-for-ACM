#include "stdafx.h"
#include <stdio.h>
#include <string.h>
//yilianmengbi
#pragma warning( disable : 4996)
int notcheck=0;
struct chesspiece{ int a0;int b0;char c0; }ch[50];
char chess[20][15]; 
int a,b,c;
void f(int p1,int p2);
int	ob(char c1, int p1, int p2,int p3)
{
	int count = 0,p11=p1,p21=p2;
	//p21>p11
	if (p1 > p2)
	{
		p21 = p1;
		p11 = p2;
	}
	for (int i = p11;i < p21;i++)
	{
		//printf("%d %d  %d\n",p11 ,p21,p3);
		if (c1 == 'H')
		{
			if (chess[i][p3] != ' ')
				count++;
		}
		else
		{
			if (chess[p3][i] != ' ')
				count++;
		}
	}
	//printf("%d  \n",count);
	return count;
}
int main()
{
	//define
	int a1,b1,c1;
	scanf("%d%d%d", &a, &b, &c);
	//printf("1 %d %d %d \n", a, b, c);
	while (!(a==0 && b==0 && c==0))
	{
		//printf("1 %d %d %d \n", a, b, c);
		 notcheck = 0;
		
		//initialise
		memset(chess,' ',sizeof(chess));
		
		//scan
		//printf("2 %d %d %d \n", a, b, c);
		for (int i = 1;i <= a;i++)
		{
			getchar();
			scanf("%c%d%d", &a1, &b1, &c1);
			//printf("3 %d %d %d \n", a, b, c);
			//printf("2 %c %d %d \n", a1, b1, c1);
			chess[b1][c1] = a1;
			ch[i].a0 = b1;
			ch[i].b0 = c1;
			ch[i].c0 = a1;
			//printf("3 %d %d %d \n", a, b, c);
		//	printf("4  \n");
		}
		//printf("3  \n");
		//iterate possible move call f
		//printf("4 %d %d %d \n", a, b, c);
		if (c == 5)
		{
			f(b,4);f(b,6);
			
		}
		else f(b,5 );
		//printf("5  \n");
		
		if (b == 2)
		{
			f(1,c); f(3,c);
			
		}
		else	f(2,c);
		

		//print
		//printf("1  \n");
		if (notcheck)

		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		//printf("2  \n");
		//format
		scanf("%d%d%d", &a, &b, &c);
	}
	
	return 0;
}
//check if move is possible
void f(int p1,int p2)

{
	//printf("hi\n");
	for (int i = 1; i <= a;i++)
	{
		//printf("hiiiizz\n");
		if (ch[i].c0 == 'G')
		{
			//printf("1  \n");
			if (p2== ch[i].b0)
			{
				//printf("2  \n");
				//printf("%d %d\n", p1,ch[i].a0);
				if (ob('H', p1, ch[i].a0, p2) == 0)
				{
					//printf("gg1\n");
					return;
				}
			}
		}
		if (ch[i].c0 == 'R')
		{
			if (p2 == ch[i].b0  && ob('H', p1, ch[i].a0,p2) == 0)
			{
				return;
			}
			else if (p1 == ch[i].a0&& ob('V', p2, ch[i].b0,p1) == 0)
			{
				return;
			}
		}
		if (ch[i].c0 == 'C')
		{
			if (p2 == ch[i].b0  && ob('H', p1, ch[i].a0,p2) == 1)
			{
				return;
			}
			else if (p1 == ch[i].a0&& ob('V', p2, ch[i].b0,p2) == 1)
			{
				return;
			}
		}if (ch[i].c0 == 'H')
		{
			int d1, d2,c1=1,c2=1;
			d1 = p2 - ch[i].b0;//dy
			//d12>=0
			if (d1 < 0)
			{
				c1 = -1;
			}
				d2 = p1 - ch[i].a0;//dx
				if (d2 < 0)
				{
					c2 = -1;
				}
				//ischecked
				if (d1 != 0 && d2 != 0 && d1*c1 + d2*c2 == 3)
				{
					int e1, e2;
					if (d1*c1>d2*c2 && chess[ch[i].a0][(ch[i].b0 + p2) / 2] == ' ')
						return;
					else if (chess[(ch[i].a0 + p1) / 2][ch[i].b0] == ' ')
						return; 
				}
		}
	}
	notcheck = 1;
	return; 
}


