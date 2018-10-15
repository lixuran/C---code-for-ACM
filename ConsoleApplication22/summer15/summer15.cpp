// summer15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
int color[21][21] = {0};
int f[21][21] = { 0 };
int c[4] = { 0,0,1,-1 };
int d[4] = { 1,-1,0,0 };
struct Point {
	int x;
	int y;
	Point(int x=0, int y=0) :x(x), y(y) {};

};
queue<Point> a;
int main()
{
	int w, h,x,y;
	char c1;
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0;i < h;i++)
		{
			for (int j = 0;j < w;j++)
			{
				f[i][j] = 0;
				cin >> c1;
				if (c1 == '.')
				{
					color[i][j] = 1;
				}
				if (c1 == '@')
				{
					x = i;
					y = j;
					f[i][j] = 1;
				}
				if (c1 == '#')
					color[i][j] = 0;
			}
		}
		int count = 1;
		a.push(Point(x, y));
		while (!a.empty())
		{
			Point e = a.front();
			a.pop();
			for (int i = 0;i < 4;i++)
			{
				int x1 = e.x + c[i], y1 = e.y + d[i];
				if (x1 >= 0 && x1 < h && y1 < w && y1 >= 0 && !f[x1][y1] && color[x1][y1])
				{
					count++;
					f[x1][y1] = 1;
					a.push(Point(x1, y1));
				}
			}

		}
		cout << count<<endl;
	}
    return 0;
}

