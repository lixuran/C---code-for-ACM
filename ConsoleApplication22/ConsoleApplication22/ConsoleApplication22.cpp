// ConsoleApplication22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning( disable : 4996)

int main()
{
	

	int n;
	char c[1000] = "";
	scanf("%d", &n);
	while (n != 0)
	{
		int i, j, a[1000] = { 0 }, mark = 0, max = 0;
		char s[1000][15], b[15];
		for (i = 0;i < n;i++)
		{
			scanf("%s", b);
			//printf("%s\n",b);
			for (j = 0;j < mark;j++)
			{
				if (strcmp(b,s[j])==0)
				{
					a[j]++;
					//printf("1 %d\n", j);
					break;
				}

			}
			if (j == mark)
			{
				a[j]++;
				strcpy(s[mark++], b);
				//printf("2 %d\n", j);

			}
		}
		for (i = 0;i < mark;i++)
		{
			if (a[i] > max)
			{
				max = a[i];
				strcpy(b, s[i]);
			}

		}
		strcat(c, b);
		strcat(c, "\n");
		scanf("%d", &n);
	}
	printf("%s", c);
    return 0;
}

