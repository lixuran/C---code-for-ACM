// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#pragma warning( disable : 4996)
int main()
{
	int i, j, k,a,n,i1,j1,k1,y;
	y = 360;
	double x = y * y * y,num=0;
	scanf("%d", &n);
	for (i = 0;i < y;i++)
	{
		for (j = 0;j < y;j++)
		{
			for (k = 0;k < y;k++)
			{
				i1 = i;j1 = j;k1 = k;
				if (i1<j1)
				{
					i1 = j;
					j1 = i;
				}
				if (i1 < k1)
				{
					
					k1 = i1;
					i1 = k;
				}
				if (j1 < k1)
				{
					a = j1;
					j1 = k1;
					k1 = a;
				}
				//printf("%d %d %d   ", i, j, k);
				if (((i1 - j1) >=y/360*n) && ((j1 - k1) >=y/360* n) && ((k1 + y - i1) >= y/360*n))
					num++;
				
					
			}
		}
	}
	printf("%f", num);
	printf("%f", num / x);
    return 0;
}

