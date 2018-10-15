// summer13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dp[66000][20];
int ch[66000][20] = { 0 };
int r[17][17];
struct Point {
	short x;
	int last;
	Point(short x=0, int y=0): x(x), last(y) {};

};
queue<Point> a;

vector<Point > d;
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> r[i][j];
		}
	}
	short b;
	int x=1;
	for (int i = 1;i < 1 << n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			dp[i][j] = -1;
		}
	}
	dp[1][1] = 0;
	/*for (int i = 1;i <= n;i++)
	{
		dp[x][i] = 0;
		x *= 2;
	}*/
	int layer=0;
	a.push(Point(1,1));
	while (!a.empty())
	{
		Point c = a.front();
		a.pop();
		if (ch[c.x][c.last])
			continue;
		for (int i = 1;i < n;i++)
		{
			if (!(c.x & 1 << i))
			{
				//cout << c.x<<' '<<c.last<<' '<<i<<endl ;
				//cout << (c.x + (1 << i)) << ' ' << i+1<<' '<< dp[c.x + (1 << i)][i + 1] << endl;
				if (dp[c.x + (1 << i)][i+1] == -1)
				{
					//cout << (c.x + (1 << i)) << endl;
					dp[c.x + (1 << i)][i+1] = dp[c.x][c.last] + r[c.last][i+1];
					d.push_back(Point(c.x + (1 << i), i+1));
				}
				else if (dp[c.x + (1 << i)][i+1] > dp[c.x][c.last] + r[c.last][i+1])
				{
					dp[c.x + (1 << i)][i+1] = dp[c.x][c.last] + r[c.last][i+1];
					d.push_back(Point(c.x + (1 << i), i+1));
				}
			}
		}
		ch[c.x][c.last] = 1;
		if (a.empty() && layer != n)
		{
			layer++;
			while (!d.empty())
			{
				a.push(d.back());
				d.pop_back();
			}
		}
	}
	/*
	int min = 100000;
	for (int i = 2;i <= n;i++)
	{
		cout << dp[(1 << n) - 1][i]<<endl;
		if (dp[(1 << n) - 1][i] < min && dp[(1 << n) - 1][i] != -1)
		{
			min = dp[(1 << n) - 1][i];
			//cout << min;
		}
	}*/
	cout << dp[(1 << n) - 1][n];
    return 0;
}

