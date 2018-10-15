// summer17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Point {
	int x;
	int c;
	int state;
	Point(int x=0,int c=0,int z=0) : x(x),c(c),state(z) {};
};
queue<Point > b;
int n, k,cou;
int main()
{
	char ch[10][10];
	while (cin >> n >> k)
	{
		//clear!!initialise
		if (n == -1 && k == -1)break;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				cin >> ch[i][j];
			}
		}
		int ans = 0;
		b.push(Point(0, 0, 0));
		while (!b.empty())
		{
			Point c = b.front();
			b.pop();
			if (c.c == k) { ans++; 
			continue;
			}
			for (int i = c.x + 1;i <= n;i++)
			{
				for (int j =1 ;j <= n;j++)
				{
					//int xx = !c.state &(1 << (j - 1));
					//cout << i << ' ' << j << ' ' << (!(c.state &(1 << (j - 1))))<< endl;
					if (ch[i][j] == '#' && (!(c.state &(1 << (j - 1)))))
					{
						b . push(Point(i , c.c + 1, c.state + (1 << (j - 1))));
					}
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}

