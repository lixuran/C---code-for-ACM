// summer7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
int v[105][105];
int h[105][105];
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
struct Point {

	int r, c,h;
	Point(int r, int c, int h) :r(r), c(c), h(h) {};
	bool operator<(const Point & a) const
	{
		return h > a.h;
	}
};
priority_queue<Point> a;
int main()
{
	int r, d,max=0;
	cin >> r >> d;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < d;j++)
		{
			v[i][j] = 1;
			cin >> h[i][j];
			a.push(Point(i, j, h[i][j]));
		}
	}
	while (!a.empty())
	{
		Point c=a.top();
		a.pop();
		for (int i = 0;i < 4;i++)
		{
			//cout << c.r << ' ' << c.c << endl;
			int x1 = c.r + x[i], y1 = c.c + y[i];
			//cout << x1 << ' ' << y1 << endl;
			if (x1 < r && x1 >= 0 && y1 < d &&y1 >= 0 && h[x1][y1]<c.h && v[c.r][c.c] <= v[x1][y1] )
			{
				v[c.r][c.c] = v[x1][y1] + 1;
			}
		
		}
		if (v[c.r][c.c] > max)
			max = v[c.r][c.c];
	}
	cout << max;
    return 0;
}

