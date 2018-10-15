// summer21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
struct Point {
	int x;int y;int t;int ti;
	Point(int x, int y,int t,int ti) :x(x), y(y) ,t(t),ti(ti){};
};
int check[210][210][11] = {0};
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0 };
char map[210][210];
queue<Point> a;
int m, n, t;
int main()
{
	int x,y,x0,y0,min=-1;
	cin >> m >> n >> t;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '@')
			{
				x0 = i;y0 = j;
			}
			if (map[i][j] == '+')
			{
				x = i;y = j;
			}
		}
	}
	a.push(Point(x0, y0, t,0));
	//check[x0][y0][t] = 1;
	while (!a.empty())
	{
		Point p = a.front();
		a.pop();
		if (check[p.x][p.y][p.t] )
			continue;
		check[p.x][p.y][p.t] = 1;
		//cout << p.x << ' ' << p.y << ' ' << p.t << endl;
		for (int i = 0;i < 4;i++)
		{
			int x1 = p.x + dx[i], y1 = p.y + dy[i];
			if (x1 >= 0 && x1 < m &&y1 >= 0 && y1 < n)
			{
				if (map[x1][y1] == '*')
				{
					a.push(Point(x1, y1, p.t, p.ti + 1));
				}
				if (map[x1][y1] == '#' && p.t!=0)
				{
					a.push(Point(x1, y1, p.t-1, p.ti + 1));
				}
				if (map[x1][y1] == '+' )
				{
					if (min == -1)
						min = p.ti+1;
					else if (min > p.ti+1)
						min = p.ti+1;
				}

			}
		}
	}
	cout << min;
    return 0;
}

