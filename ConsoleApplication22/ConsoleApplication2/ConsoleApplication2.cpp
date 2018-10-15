// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#pragma warning( disable : 4996)
int main()
{
	int n;
	scanf("%d", &n);
	int i, j,i1,j1,x;
	double num;
	while (n != -1)
	{
		 num = 0;
		 x = 360000 - 2000 * n;
		for (i = 0;i < x;i++)
		{
			
			
			if (i>1000*n)
				num += i - 1000*n;
			if (x - 1000*n>i)
				num += x - i - 1000*n;
			
		}
		printf("%.3f\n", num / (36000 * 36000));
		scanf("%d", &n);
	}
	return 0;
}

