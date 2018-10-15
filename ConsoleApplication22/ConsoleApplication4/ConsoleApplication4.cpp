#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#pragma warning( disable : 4996)
int main()
{
	int m,n,i,j,check,count=1,counts=0,exist=0;
	char c;
	int ma[50][50];scanf("%d", &n);
	while (n!=-1)
	{
		printf("Problem #%d\n\n", count++);
		scanf("%d", &m);
		
		exist = 0;
		for (int i1 = 0;i1 < 50;i1++)
		{
			for (int j1 = 0;j1 < 50;j1++)
			{
				ma[i1][j1] = 0;
			}
		}
		for (int k = 0; k < m;k++)
		{
			scanf("\n%c", &c);scanf("%d", &i);scanf("%d", &j);
			//printf("%d %c %d %d\n", k,c, i,j);
			i--;
			j--;
			if (c == 'H' )
			{
				if (ma[i][j] == 0)
				ma[i][j] = 1;
				else
					ma[i][j] = 12;

			}
			else
			{
				if (ma[j][i] == 0)
					ma[j][i] = 2;
				else
					ma[j][i] = 12;

			}
		}
		printf("%d\n", ma[0][1]);
		printf("%d\n", ma[0][2]);
		for (int k = 0; k <n;k++)
		{
			counts = 0;
			for (int x = 0;x < n-k;x++)
			{
				for (int y = 0;y < n - k;y++)
				{
					 check = 1;
					for (int z = 0;z <= k;z++)
					{
						if ((ma[x][y + z] != 1 && ma[x][y + z] != 12) || (ma[x+k+1][y+z]!=1 && ma[x + k + 1][y + z] != 12) || (ma[x+z][y]!=2&& ma[x + z][y] != 12) || (ma[x + z][y+k+1] != 2 && ma[x + z][y + k + 1] != 12))
						{
							check = 0;
							break;
						}
					}
					if (check == 1)
					{
						counts++;
						printf("%d %d %d\n", k + 1, x, y);
						exist = 1;
					}
					
				}
			}
			if (counts != 0)
				printf("%d square of size %d\n",counts,k+1 );
		}
		if (!exist)
		{
			printf("No completed squares can be found.");
		}
		printf("\n**********************\n");
		scanf("%d", &n);
	}
	return 0;
}

