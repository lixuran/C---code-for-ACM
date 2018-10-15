// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;
#pragma warning( disable : 4996)
int d, s, b;//disk , sizeofblock,blocks per disk
char p;//parity
//int disk[105][7];这个方法太麻烦 最大64位的话要用到unsigned long 计算浪费 应直接采用二进制计算
int e[6][6500];
int main()
{
	int count = 0;
	while (scanf("%d%d%d", &d, &s, &b) == 3 && d != 0)
	{
		count++;
		int temp = 0, countline;
		char c;
		getchar();
		p = getchar();
		getchar();
		//memset(disk, 0, sizeof(disk));
		memset(e, 0, sizeof(e));
		int c1 = 0, c2 = 0, check = 0;
		for (int m = 0;m < d;m++)
		{


			for (int i = 0; i < s*b;i++)
			{
				c = getchar();
				//printf("%c ", c);
				if (c != 'x')
				{
					e[m][i] = (int)c-'0';
				}
				else
				{
					e[m][i] = -1;
				}
			}
			getchar();
		}
		for (int i = 0;i < s*b;i++)
		{
			c1 = 0;c2 = 0;
			int x = 0;
			if (p == 'O')
				c2++;
			//printf("c2   : %d\n", c2);
			for (int j = 0;j < d;j++)
			{
				if (e[j][i] == -1)
				{
					c1++;
					x = j;
				}
				else
				{
					c2 = (c2 + e[j][i]) % 2;
					//printf("e   : %d\n", e[j][i]);
				}
			}
			if (c1 == 0)
			{
				if (c2 % 2 != 0)
				{
					//printf("c2: %d\n", c2);
					printf("1 Disk set %d is invalid.\n", count);
					check = 1;
					break;
				}
			}
			else if (c1 == 1)
			{
				e[x][i] = c2%2;
			}
			else
			{
				printf("2 Disk set %d is invalid.\n", count);
				check = 1;
				break;
			}
		}
		if (check != 1)
		{
			printf("Disk set %d is valid, contents are: ", count);
			int cou = 0, cou2 = 0;
			for (int i = 0;i < b;i++)
			{
				for (int j = 0;j < d;j++)
				{
					if (i%d == j)
						continue;
					for (int z = 0;z < s;z++)
					{
						cou++;
						cou2 = cou2 * 2 + e[j][i*s + z];
						//printf("aa %d \n", e[j][i*s + z]);
						if (cou == 4)
						{
							cou = 0;
							printf("%d ", cou2);
							cou2 = 0;
						}

					}
				}
			}
			if (cou != 0)
			{
				while (cou++!=4)
				{
					cou2 *= 2;
				}
				printf("%d ", cou2);
			}
			printf("\n");
		}
	}

		
    return 0;
}

