// kuangbin2i.cpp: 定义控制台应用程序的入口点。
//HDU 2102 

#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
char map[2][10][10];
int n, m, t;
int vi[2][10][10];
struct N {
	int x, y, z;
	int step;
	N(int xin, int yin, int zin, int step) { x = xin; y = yin; z = zin; this->step = step; }
};
int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		memset(map, ' ', sizeof(map));
		memset(vi, 0, sizeof(vi));

		cin >> n >> m >> t;
		
		for (int i = 0; i < n; i++)
		{
			cin >> map[0][i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> map[1][i];
		}
		bfs()
	}
    return 0;
}

