#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#pragma warning( disable : 4996)
int main()
{
	int n;
	char a[100] = "", b[100] = "";
	scanf("%d", &n);
	while (n!= -1)
	{
		int i, count = 0, j, check = 0, c[100] = {0};
		printf("Round %d\n", n);
		scanf("%s", &a);
		scanf("%s", &b);
		int checkwin;
		for (i = 0; i < strlen(b);i++)
		{
			 checkwin = 1;
			 
			for (j = 0;j < strlen(a);j++)
			{

				if (a[j] == b[i])
				{
					c[j] = 1;
					check = 1;	
				}
				if (c[j] == 0)
					checkwin = 0;
			}
			if (checkwin)
			{
				printf("You win.\n");
				break;
			}
			if (check == 0)
				count++;
			else check = 0;
			if (count == 7)
			{

				printf("You lose.\n");
				break;
			}
		}
		if (checkwin!=1 && count != 7)
		{
			printf("You chickened out.\n");
		}
		scanf("%d", &n);
	}
	return 0;
}

//求最大的i，使得a[i] = key，若不存在，则返回-1
int myupper_bound2(int A[], int x, int y, int key) {
	while (x < y) {
		int m = x + ((y + 1 - x) >> 1);//向上取整
		if (A[m] <= key) x = m;
		else y = m - 1;
	}
	if (A[x] == key) return x;
	return -1;
}

