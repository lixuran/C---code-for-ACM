// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

using namespace std;
struct Point
{
	int	x;
	int y;
	
}point[10000];
int main()
{
	int n;
	int count[10000] = {0};
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		memset(count, 0, sizeof(count));
		memset(point, 0, sizeof(point));
		for (int i = 0;i < num;i++)
		{
			int x, y;
			cin >> x >> y;
			point[i].x = x;
			count[x]++;
			point[i].y = y;
		}
		for (int i = 0;i < num;i++)
		{
			for (int j = i + 1;j < num;j++)
			{
				if (point[i].x > point[j].x || (point[i].x == point[j].x && point[i].y > point[j].y))
				{
					Point c=point[i];
					point[i] = point[j];
					point[j] = c;
				}
			}
		}
		int check = 1;
		int middle = point[0].x + point[num - 1].x;
		for (int i = 0;i < num/2;i++)
		{
			for (int j = count[point[i].x];j>0;j--)
			{
				if (point[i].y == point[num - i - j].y && (point[i].x + point[num - i - 1].x == middle))

					i++;
				else
				{
					check = 0;
					break;
				}
			}

		}
		if (check)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}

